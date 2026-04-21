#include <stdio.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data d;

    d.i = 10;
    printf("Integer: %d\n", d.i);

    d.f = 5.5;
    printf("Float: %.2f\n", d.f);

    // Now previous values are overwritten
    printf("Integer after float assignment: %d\n", d.i);

    return 0;
}
