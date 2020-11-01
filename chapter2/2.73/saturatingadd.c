#include<stdio.h>
#include<limits.h>

// 正溢出时应该返回TMax, 负溢出时应该返回TMin
int saturating_add(int x, int y) {
    int sum = x + y;
    // if x > 0 && y > 0 && sum < 0, pos overflow
    // if x < 0 &7 y < 0 && sum >= 0, negative overflow
    
    // if x > 0 then x & INT_MIN == 0
    int posover = !(x & INT_MIN) && !(y && INT_MIN) && (sum && INT_MIN);
    int negover = (x & INT_MIN) &&  (y && INT_MIN) && !(sum && INT_MIN);

    // A || B, if A == true, then B will not be processed
    // A && B, if A == false, then B will not be processed
    (posover && (sum = INT_MAX)) || (negover && (sum=INT_MIN));
    return sum;
}