#include "fmt.h"

/* "foo" -> "  foo"
 *  write padlen-srclen spaces, if that is >= 0.  Then copy srclen
 *  characters from src.  Truncate only if total length is larger than
 *  maxlen.  Return number of characters written. */
unsigned long fmt_pad(char* dest,const char* src,unsigned long srclen,unsigned long padlen,unsigned long maxlen) {
  long todo;
  char* olddest=dest;
  char* max=dest+maxlen;
  todo=padlen-srclen;
  if (dest==0) {
    int sum=srclen>padlen?srclen:padlen;
    return sum>maxlen?maxlen:sum;
  }
  for (; todo>0; --todo) {
    if (dest>max) break;
    *dest=' '; ++dest;
  }
  for (todo=srclen; todo>0; --todo) {
    if (dest>max) break;
    *dest=*src; ++dest; ++src;
  }
  return dest-olddest;
}
