#include "scan.h"

unsigned int scan_longlong(const char* src,signed long long* dest) {
  unsigned int i,o;
  unsigned long long l;
  char c=src[0];
  o=c=='-' || c=='+';
  if ((i=scan_ulonglong(src+o,&l))) {
    *dest=c=='-'?-l:l;
    return i+o;
  } return 0;
}
