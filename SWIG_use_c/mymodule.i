/* File: mymodule.i  swig -python mymodule.i*/
%module mymodule

%{
#include "nmmintrin.h"
%}

int _mm_popcnt_u32(unsigned int v);
unsigned int _mm_crc32_u8 (unsigned int crc, unsigned char v);
unsigned int _mm_crc32_u16(unsigned int crc, unsigned short v);
unsigned int _mm_crc32_u32(unsigned int crc, unsigned int v);
