#include <stdio.h>

enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };

int main() {
    enum Day today;

    today = WED;

    printf("Value of today: %d\n", today);

    return 0;
}
