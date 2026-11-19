#include <stdio.h>

int main() {
    if (1 > 2) {
        printf("1 > 2\n");
    } else if (3 > 2) {
        printf("3 > 2\n");
    }

    if (1 > 2 || 3 > 2) {
        printf("1 > 2 or 3 > 2\n");
    }
    if (1 < 2 && 3 > 2) {
        printf("1 < 2 and 3 > 2\n");
    }

    return 0;
}

