#include<stdio.h>
#include<inttypes.h>

typedef unsigned char *byte_pointer;

int is_little_endian();
void show_bytes(byte_pointer start, size_t len);

int main() {
    if (is_little_endian()) {
        printf("this machine is little endian\n");
    } else {
        printf("this machine is big endian\n");
    }
    return 0;
}

int is_little_endian() {
    int flag = 0x00FF;
    //show_bytes((byte_pointer)&flag, sizeof(int));
    short* ptr = (short *)&flag;
    printf("%.2x\n", *ptr);
    return *ptr == 0xFF;
}

// void show_bytes(byte_pointer start, size_t len) {
//     for (int i=0; i < len; i++) {
//         printf(" %.2x", start[i]);
//     }
//     printf("\n");
// }