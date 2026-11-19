#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
} array;

int main() {
    array arr = { 1, 2, 3 };
    array* parr = &arr;
    printf("Original Array: [%d, %d, %d]\n", arr.a, arr.b, arr.c);

    (*parr).a = 4;
    parr->b = 5;
    parr->c = 6;
    printf("New Array: [%d, %d, %d]\n", arr.a, arr.b, arr.c);

    return 0;
}


