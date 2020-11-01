#include<stdio.h>
#include<inttypes.h>


/**
 * 在下列四种情况下返回 1， 其余情况返回0 
 *   A. x的任何位都为1
 *   B. x的任何位都为0
 *   C. x的最低有效字节中的位都为1
 *   D. x的最高有效字节中的位都为0
 **/
int cal(int x);

int main(){
    printf("cal(0xFFFFFFFF) = %d\ncal(0x00000000) = %d\ncal(0x123456FF) = %d\ncal(0x00123456) = %d\ncal(0xFF123400) = %d\n", 
                cal(0xFFFFFFFF),cal(0x00000000),cal(0x123456FF),cal(0x00123456),cal(0xFF123400));
    return 0;
}

int cal(int x) {
    return ((x&~0) == 1)
        || ((x|~0) == 0)
        || ((x&0xFF) == 0xFF)
        || ((x>>((sizeof(int)-1)*8) == 0));
}