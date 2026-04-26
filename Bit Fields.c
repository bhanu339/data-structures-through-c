#include <stdio.h>

struct Flags {
    unsigned int a : 1;  // 1 bit (0 or 1)
    unsigned int b : 1;  // 1 bit
    unsigned int c : 1;  // 1 bit
};

int main() {
    struct Flags f;

    f.a = 1;
    f.b = 0;
    f.c = 1;

    printf("a = %u\n", f.a);
    printf("b = %u\n", f.b);
    printf("c = %u\n", f.c);

    return 0;
}
