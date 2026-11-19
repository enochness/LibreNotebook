#include <stdio.h>

int main() {
    int num = 5;
    printf("Original num: %d\n", num);

    int* pNum = &num;
    *pNum = 10;
    printf("New num: %d\n", num);

    return 0;
}


