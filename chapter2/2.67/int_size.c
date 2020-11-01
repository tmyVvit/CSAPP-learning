#include<stdio.h>

// return 1 if int is 32 bits
int int_size_is_32();
int int_size_is_32_for_16();

int main(){
    if (int_size_is_32() && int_size_is_32_for_16()) {
        printf("int size is 32 bit in this machine\n");
    } else {
        printf("int size is not 32 bit in this machine\n");
    }
    return 0;
}

int int_size_is_32() {
    int set_msb = 1 << 31;
    return set_msb && !(set_msb << 1);
}

int int_size_is_32_for_16() {
    int msb_16bit = 1 << 15 << 1;
    return (msb_16bit << 1) && (msb_16bit << 15) && !(msb_16bit << 15 << 1);
}