#include<stdio.h>

int odd_ones(unsigned x);

int main(){
    printf("0x1: %d\n0x80:%d\n0xffffffff:%d\n", odd_ones(0x1), odd_ones(0x80), odd_ones(0xffffffff));
    return 0;
}

// 相同数之间的异或等于0
// 可以将x看作高位和低位两部分， 将两部分进行异或运算，得到的结果的1的奇偶性不会改变
// e.g.  x = 0x87  1 0 0 0  0 1 1 1
// 高位与低位异或：   0 0 0 0  1 0 0 0
//                          1 1 1 1 此时可以将高位舍弃，只需要看低位的数就可以判断
// 继续异或运算               0 0 1 1 
//                              0 0
//                                0
//                                0    ==》 数x有偶数个1 
int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 0x1;
}