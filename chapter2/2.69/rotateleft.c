#include<stdio.h>

int rotate_left(unsigned x, int n);

int main() {
    printf("rotate_left(0x12345678, 4)=0x%x\nrotate_left(0x12345678, 0)=0x%x\nrotate_left(0x12345678, 20)=0x%x\n"
            ,rotate_left(0x12345678, 4),rotate_left(0x12345678,0), rotate_left(0x12345678, 20));
}

int rotate_left(unsigned x, int n) {
    unsigned top = x << n;
    int len = (sizeof(unsigned)<<3) - n;
    unsigned lower = ((-1 << len) & x) >> len;
    return top|lower;
}