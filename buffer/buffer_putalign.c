#include "byte.h"
#include "buffer.h"

int buffer_putalign(buffer* b,const char* buf,unsigned int len) {
  int tmp;
  while (len>(tmp=b->n-b->p)) {
    byte_copy(b->x+b->p, tmp, buf);
    b->p+=tmp;
    buf+=tmp;
    len-=tmp;
    if (buffer_flush(b)<0) return -1;
  }
  byte_copy(b->x+b->p, len, buf);
  b->p+=len;
  return 0;
}
