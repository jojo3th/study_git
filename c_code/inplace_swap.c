#include <stdio.h>

#define INPLACE_SWAP(type, a, b) \
{ \
    *a = *a ^ *b; \
    *b = *a ^ *b; \
    *a = *a ^ *b; \
}

int main() {
    int a = 20;
    int b = 10;

    INPLACE_SWAP(int, &a, &b);
    printf("a = %d,b = %d\n", a, b);
    printf("修改");
}