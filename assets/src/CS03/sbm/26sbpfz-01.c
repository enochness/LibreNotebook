#include <stdio.h>

int main() {
    int a = 5;
    double b = 0.1;
    char c = 'A';

    int* pA = &a;
    double* pB = &b;
    char* pC = &c;

    printf("%d, %p\n", a, pA);
    printf("%f, %p\n", b, pB);
    printf("%c, %p\n", c, pC);

    return 0;
}


