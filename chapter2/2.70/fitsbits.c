#include<stdio.h>

// return 1 when x can be represented as an n-bit, 2's-complement number
// 1 <= n <= w
int fits_bits(int x, int n);

int main() {
    printf("fits_bits(0x1, 3)=%d\nfits_bits(0x80, 7)=%d\n", fits_bits(0x1, 3), fits_bits(0x80, 7));
    return 0;
}

int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    return ((x << (w - n)) >> (w - n)) ==  x;
}