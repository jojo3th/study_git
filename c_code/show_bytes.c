#include <stdio.h>
#include <stdlib.h>

#define PRINT_BINARY(type, x) \
    { \
        int i; \
        unsigned y = (unsigned)x; \
        for (i = sizeof(type) * 8 - 1; i >= 0; i--) { \
            printf("%d", (y >> i) & 1); \
        } \
        printf("\n"); \
    }

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    PRINT_BINARY(int, ival);
    show_float(fval);
    PRINT_BINARY(float, fval);
    show_pointer(pval);
}

int main(int argc, char *argv[]) {
    int val = 12345;
    if (argc > 1) {
        val = strtol(argv[1], NULL, 0);
    }
    test_show_bytes(val);
    return 0;
}