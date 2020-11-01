#include<stdio.h>
#include<inttypes.h>

#define LOWEST 0xFF

int cal(int32_t x, int32_t y);

int main(){
    printf("%X\n", cal(0x89ABCDEF, 0x76543210));
    return 0;
}

int cal(int32_t x, int32_t y) {
    return (x & LOWEST) + (y & ~LOWEST);
}
