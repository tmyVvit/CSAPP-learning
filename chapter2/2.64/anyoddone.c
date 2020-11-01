#include<stdio.h>
#include<inttypes.h>

int any_odd_one(unsigned x);

int main(){
    printf("any_odd_one(0x1)=%d\nany_odd_one(0x2)=%d\n", any_odd_one(0x1), any_odd_one(0x2));
}

int any_odd_one(unsigned x) {
    // 如果存在奇数位为1, 那么 0xAAAAAAAA & x > 0 
    //                 => !(0xAAAAAAAA & x) = 0 
    //                 => !!(0xAAAAAAAA & x) = 1
    return !!(0xAAAAAAAA & x);
}