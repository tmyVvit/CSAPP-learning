#include<stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum);

int main(){
    printf("xbyte(0x00FF0000, 2)=0x%x\nxbyte(0x00FF1234, 1)=0x%x\nxbyte(0xAB123456, 3)=0x%x\n",
            xbyte(0x00FF0000, 2), xbyte(0x00FF1234, 1), xbyte(0xAB123456, 3));
    
    return 0;
}

int xbyte(packed_t word, int bytenum) {
    int extracted = (word >> (bytenum << 3)) & 0xFF;
    int sig = (extracted >> 7) & 0x01;
    int mask = ~0xFF;
    // if sig == 1, need mask else mask = 0
    mask &= !sig - 1;
    return extracted | mask;
}