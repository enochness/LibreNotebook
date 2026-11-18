#include <stdio.h>

int main() {
    const int FIXED_VALUE = 5;
    int arr[5] = { 1, 2, 3, 4, 5 };
    double tensor[2][3] = {{0.0, 0.1, 0.2},
                           {1.0, 1.1, 1.2}};
    char string[10] = "string";

    printf("Fixed value: %d\n", FIXED_VALUE);
    printf("Second element of the array: %d\n", arr[1]);
    printf("Second row, third column: %f\n", tensor[1][2]);
    printf("Third charater in the string: %c\n", string[2]);

    return 0;
}


