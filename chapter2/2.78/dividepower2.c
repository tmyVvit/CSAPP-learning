#include<stdio.h>
#include<limits.h>

// divide by power of 2, assume 0 <= k <= w-1
int divide_power2(int x, int k) {
    int negtive = x & INT_MIN;
    negtive && (x = x + (1<<k)-1);
    return x>>k;
}

int main() {
    return 0;
}
