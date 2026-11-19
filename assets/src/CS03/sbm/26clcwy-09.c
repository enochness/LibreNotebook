#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    int ctr = 0;
    while (ctr < 5) {
        printf("%d ", ctr);
        ctr++;
    }
    printf("\n");

    do {
        printf("%d ", ctr);
        ctr++;
    } while (ctr < 0);
    printf("\n");

    return 0;
}


