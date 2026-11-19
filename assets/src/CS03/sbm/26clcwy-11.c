#include <stdio.h>

double square(double num);

int main () {
    printf("1.4^2 is equal to %f\n", square(1.4));

    return 0;
}

double square(double num) {
    return num * num;
}


