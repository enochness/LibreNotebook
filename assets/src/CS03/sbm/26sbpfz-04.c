#include <stdio.h>
#include <stdlib.h>

int main() {
    int* num = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        num[i] = i;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    free(num);

    return 0;
}


