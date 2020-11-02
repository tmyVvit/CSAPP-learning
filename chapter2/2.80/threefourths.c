#include<stdio.h>
#include<inttypes.h>
#include<limits.h>
#include<assert.h>

int threefourths(int x);

int main(){
    assert(threefourths(8) == 6);
    assert(threefourths(9) == 6);
    assert(threefourths(10) == 7);
    assert(threefourths(11) == 8);
    assert(threefourths(12) == 9);

    assert(threefourths(-8) == -6);
    assert(threefourths(-9) == -6);
    assert(threefourths(-10) == -7);
    assert(threefourths(-11) == -8);
    assert(threefourths(-12) == -9);
    return 0;
}

// calculate 3/4 * x, no overflow
int threefourths(int x) {
    // split x to t and l
    // x = t + l
    // then calculate t/4 * 3, l*3 / 4
    int t = x & ~0x3;
    int l = x & 0x3;
    int td4 = t >> 2;
    int td4m3 = (td4<<1) + td4;

    int lm3 = (l<<1) + l;
    // when divide 4, need to consider rounding zero
    // just like divide power2
    int isneg = x & INT_MIN;
    (isneg) && (lm3 += ((1<<2) - 1));
    int lm3d4 = (lm3 >> 2);
    return lm3d4 + td4m3;
}