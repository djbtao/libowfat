#include <sys/socket.h>
#include <netinet/in.h>
#include "byte.h"
#include "uint16.h"
#include "uint32.h"
#include "socket.h"

int socket_bind4(int s,const char *ip,uint16 port) {
  struct sockaddr_in si;
  byte_zero(&si,sizeof si);
  si.sin_family = AF_INET;
  uint16_pack_big((char*) &si.sin_port,port);
  *(uint32*)&si.sin_addr = *(uint32*)ip;
  return bind(s,(struct sockaddr*)&si,sizeof si);
}
