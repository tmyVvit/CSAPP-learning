#include<stdio.h>

int A(int k);
int B(int k, int j);

int main(){
    printf("A(4)=0x%x\nA(1)=0x%x\nB(4,4)=0x%x\nB(1,1)=0x%x\n", A(4), A(1), B(4, 4), B(1, 1));
    return 0;
}

int A(int k) {
    // return 1^(w-k)0^k 
    // a^k means k times a
    return ~((1<<k)-1);
}

int B(int k, int j) {
    // return 0^(w-k-j)1^k0^j
    return (~A(k+j)) ^ (~A(j));
}