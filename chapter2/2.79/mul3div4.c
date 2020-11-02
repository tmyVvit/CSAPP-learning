#include<stdio.h>
#include<limits.h>
#include<inttypes.h>
#include<assert.h>

int mul3div4(int x);
int divide_power2(int x, int k);

int main(){
    return 0;
}

int mul3div4(int x) {
    // will overflow !!
    int mul3 = (x<<1)+1;
    return divide_power2(mul3, 2);
}

int divide_power2(int x, int k) {
    int negtive = x & INT_MIN;
    negtive && (x = x + (1<<k)-1);
    return x>>k;
}