#include <assert.h>
#include "safemult.h"

int main() {
  int16 a;
  int32 b;
  int64 c;
  uint16 d;
  uint32 e;
  uint64 f;

  assert(imult16(4,10000,&a)==0);
  assert(imult16(-4,10000,&a)==0);
  assert(imult16(5,10,&a)==1 && a==50);
  assert(imult16(-3,10000,&a)==1 && a==-30000);

  assert(imult32(0x40000000,2,&b)==0);
  assert(imult32(-0x40000000,2,&b)==1 && b==-0x80000000);
  assert(imult32(0x3fffffff,2,&b)==1 && b==0x7ffffffe);

  assert(imult64(0x4000000000000000ll,2,&c)==0);
  assert(imult64(-0x4000000000000000ll,2,&c)==1 && c==-0x8000000000000000ll);
  assert(imult64(0x3fffffffffffffffll,2,&c)==1 && c==0x7ffffffffffffffell);

  return 0;
}