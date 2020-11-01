#include<stdio.h>
#include<inttypes.h>

#define LOWEST 0xFF

int replace_byte(unsigned x, int i, unsigned char b);

int main(){
    printf("0x%X\n0x%X\n", replace_byte(0x12345678, 2, 0xAB), replace_byte(0x12345678, 0, 0xAB));
    return 0;
}

int replace_byte(unsigned x, int i, unsigned char b) {
    x = x & (~(LOWEST<<(i*sizeof(int)))); 
    return x | (b << (i*sizeof(int)));
}