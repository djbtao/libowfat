#ifndef UINT16_H
#define UINT16_H

typedef unsigned short uint16;
typedef   signed short  int16;

#if defined(__i386__) && !defined(NO_UINT16_MACROS)
#define uint16_pack(out,in) (*(uint16*)(out)=(in))
#define uint16_unpack(in,out) (*(out)=*(uint16*)(in))
#define uint16_read(in) (*(uint16*)(in))
extern void uint16_pack_big(char *out,uint16 in);
extern void uint16_unpack_big(const char *in,uint16* out);
extern uint16 uint16_read_big(const char *in);
#else

extern void uint16_pack(char *out,uint16 in);
extern void uint16_pack_big(char *out,uint16 in);
extern void uint16_unpack(const char *in,uint16* out);
extern void uint16_unpack_big(const char *in,uint16* out);
extern uint16 uint16_read(const char *in);
extern uint16 uint16_read_big(const char *in);

#endif

#endif
