#include <stdio.h>

int main() {
    char str[] = "Hello";
    char* ptr = str;

    *ptr = 'A';
    printf("%s\n", str);

    *(ptr + 2) = 'A';
    printf("%s\n", str);

    return 0;
}


