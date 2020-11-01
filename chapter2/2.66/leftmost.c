#include<stdio.h>

// Generate mask indicating leftmost 1 in x. assume x = 32
// e.g. 0xFF00 -> 0x8000, 0x6600 -> 0x4000, 0xFA00 -> 0x8000
int leftmost_one(unsigned x);

int main(){
    printf("leftmost_one(0xFF00)=0x%x\nleftmost_one(0x6600)=0x%x\nleftmost_one(0x0)=0x%d\n", leftmost_one(0xFF00), leftmost_one(0x6600),leftmost_one(0x0));
    return 0;
}

int leftmost_one(unsigned x) {
    // 首先得到 leftmost 之后所有为1的数 [000.....00111...111]
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    // 如果x==0时则不需要加1
    return (x >> 1) + (x && 1);
}