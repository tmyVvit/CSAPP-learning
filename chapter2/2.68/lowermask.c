#include<stdio.h>

int lower_mask(int k);

int main() {
    printf("lower_mask(6)=0x%x\nlower_mask(17)=0x%x\nlower_mask(32)=0x%x\n", lower_mask(6), lower_mask(17),lower_mask(32));
}

int lower_mask(int k) {
    return (1<<(k-1)<<1) -1;
}