#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int div16(int32_t x);
int div16_2(int32_t x);
 
int main() {
    printf("div16(772)=%d\tdiv16(-772)=%d\ndiv16_2(772)=%d\tdiv16_2(-772)=%d    \n", div16(772), div16(-772), div16_2(772), div16_2(-772));
    return 0;
 }
  
int div16(int32_t x) {
      int flag  = (x>>31) & 0x1;
     return (x>>4) + flag*1;
}
 
int div16_2(int32_t x) {
    int mask = (x>>31) &0xF;
    return (x+mask)>>4;
}