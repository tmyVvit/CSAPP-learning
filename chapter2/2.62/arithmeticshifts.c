#include<stdio.h>

// 判断机器的 int 的右移运算是逻辑右移还是算术右移
int int_shifts_are_arithmetic();

int main(){
    if (int_shifts_are_arithmetic()){
        printf("int shifts are arithmetic in this mathine\n");
    } else {
        printf("int shifts are logical in this machine\n");
    }
    return 0;
}

int int_shifts_are_arithmetic() {
    unsigned len = sizeof(int)*8;
    int num = 1 << (len - 1);
    return ((num >> (len - 1)) & 0x2) == 0x2;
}