#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "io_internal.h"
#ifdef HAVE_KQUEUE
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#endif
#ifdef HAVE_EPOLL
#include <sys/epoll.h>
#endif

void io_wantwrite(int64 d) {
  int newfd;
  io_entry* e=array_get(&io_fds,sizeof(io_entry),d);
  if (!e) return;
  newfd=(!e->wantread && !e->wantwrite);
  io_wanted_fds+=newfd;
#ifdef HAVE_EPOLL
  if (io_waitmode==EPOLL) {
    struct epoll_event x;
    x.events=EPOLLOUT;
    if (e->wantread) x.events|=EPOLLIN;
    x.data.fd=d;
    epoll_ctl(io_master,newfd?EPOLL_CTL_ADD:EPOLL_CTL_MOD,d,&x);
  }
#endif
#ifdef HAVE_KQUEUE
  if (io_waitmode==KQUEUE) {
    struct kevent kev;
    struct timespec ts;
    EV_SET(&kev, d, EVFILT_WRITE, EV_ADD|EV_ENABLE, 0, 0, 0);
    ts.tv_sec=0; ts.tv_nsec=0;
    kevent(io_master,&kev,1,0,0,&ts);
  }
#endif
  e->wantwrite=1;
}