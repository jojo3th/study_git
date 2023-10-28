#include <stdio.h>
#include <limits.h>

#define SWAP(type, a, b) do { \
    type temp = a; \
    a = b; \
    b = temp; \
} while (0)

int main() {
    // char a, b;
    // a = 10;
    // b = 11;
    // for (int i = sizeof(char) + 8 - 1; i >= 0; i--) {
    //     printf("%d\n", (a >> i) & 1);
    // }

    // int a = 0x12345678;
    // int m = 0xffffffff;
    // printf("%x\n", a & m);

    // int a = -214748347 - 1;
    // printf("%d\n", a);

    // int a = -INT_MIN;
    // int b = INT_MIN + INT_MIN;
    // printf("%d\n", a);
    // printf("%d\n", b);

    // unsigned和int转个锤子，强转只是改变了解释方式，而不是改变了值
    // int x = 0xFFFFFF11;
    // int y = 0xFFFFFF22;

    // unsigned ux = x;
    // unsigned uy = y;
    // unsigned uz = 0x00000000;

    // printf("%u\n", x + uz);

    // printf("%d", -1 ? 1 : 0);

    printf("hello, world");
    int x = !1;
    printf("%d  %d\n", x, !x);
    return 0;
}

int tadd_ok(int x, int y) {
    int sum = x + y;

    return (x >= 0 && sum >= 0) || (x < 0 && sum < 0);
}

int tsub_ok(int x, int y) {
    
    return tadd_ok(x, -y);
}
