#include<stdio.h>

int signed_high_prod(int x, int y);
unsigned unsigned_hign_prod(unsigned x, unsigned y);
unsigned unsigned_hign_prod_64bit(unsigned x, unsigned y);

int main(){
    printf("0x77ABCABC * 0x77000000 :\nunsigned_hign_prod_64bit: %x\nunsigned_hign_prod: %x\n", 
            unsigned_hign_prod_64bit(0x77ABCABC, 0x77000000), unsigned_hign_prod(0x77ABCABC, 0x77000000));

    return 0;
}

int signed_high_prod(int x, int y) {
    int64_t mult = (int64_t) x * y;
    return mult >> 32;
}

unsigned unsigned_hign_prod(unsigned x, unsigned y) {
    // using expression (2.18) unsigned x', y' and signed x, y:
    // x' * y' = (x + x_(w-1) * 2^w)(y + y_(w-1) * 2^w)
    //         = x * y + x_(w-1) * y + y_(w-1) * x + x_(w-1) * y_(w-1) * 2^(2w)
    int xtop = (x >> 31) & 0x1;
    int ytop = (y >> 31) & 0x1;
    return signed_high_prod(x, y) + xtop * (int) x + ytop * (int) y;
}


// checking by using 64bit int
unsigned unsigned_hign_prod_64bit(unsigned x, unsigned y) {
    u_int64_t mult = (u_int64_t) x * y;
    return mult >> 32;
}
