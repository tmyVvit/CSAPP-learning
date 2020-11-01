#include<stdio.h>

#define INTLEN (sizeof(int)*8)

// srl使用算术右移(xsra)完成逻辑右移
unsigned srl(unsigned x, int k);
// sra使用逻辑右移(xsrl)完成算术右移
int sra(int x, int k);

int main() {
    printf("srl(0x80000000, 4)=%x\nsra(0x8F000000, 4)=%x\nsra(0x0F000000, 4)=%x",
                srl(0x80000000, 4), sra(0x8F000000, 4), sra(0x0F000000, 4));
    return 0;
}

unsigned srl(unsigned x, int k) {
    // Perform shift arithmetically
    unsigned xsra = (int) x >> k;
    return xsra & ((0x1 << (INTLEN - k)) - 1);
}

int sra(int x, int k) {
    // perform shift logically
    int xsrl = (unsigned) x >> k;

    int flag = 1 << (INTLEN - 1);
    //int mask = ~0 & ((1 << k) - 1);
    int mask = (-1) << (INTLEN - k); 
    // if x < 0 then need mask, else no need mask
    mask &= !(x&flag) - 1;
    return xsrl | mask;
}