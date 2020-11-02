#include<stdio.h>
#include<inttypes.h>
#include<stdint.h>
#include<stdlib.h>

void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t buf = nmemb * size;
    // if overflow return NULL
    if (size == buf/nmemb) {
        void *ptr = malloc(buf);
        if (ptr != NULL) {
            memset(ptr, 0, buf);
        }
        return ptr;
    }
    return NULL;
}