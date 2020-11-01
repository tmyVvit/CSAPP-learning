#include<stdio.h>
#include<limits.h>

// determine if arguments can be substracted without overflow
// return 1 if no overflow
int tsub_ok(int x, int y) {
    int sub = x - y;
    // pos overflow : x > 0 && y < 0 && sub < 0
    // neg overflow : x < 0 && y > 0 && sub > 0
    int posover = !(x & INT_MIN) && (y & INT_MIN) && (sub & INT_MIN);
    int negover = (x & INT_MIN) && !(y & INT_MIN) && !(sub & INT_MIN);
    return posover || negover;
}

// Warning!  2.32
// cannot use tsub_ok(x,y) = tadd_ok(x, -y);
// cause when y = TMin, -y = TMin
// tadd_ok(x, -y) will return 1(overflow) when x < 0, return 0 when x > 0

int main() {
    printf("tsub_ok(1, INT_MIN)=%d\ntsub_ok(-1, INT_MIN)=%d\n",
            tsub_ok(1, INT_MIN), tsub_ok(-1, INT_MIN));
    return 0;
}