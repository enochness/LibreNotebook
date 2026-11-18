#include <stdio.h>

typedef struct {
    float a;
    float b;
    float c;
} array ;

struct vector {
    float x;
    float y;
};

int main() {
    // Using vec
    struct vector vec;
    vec.x = 0.1;
    vec.y = 0.2;
    printf("v   = <%f, %f>\n", vec.x, vec.y);

    // Using arr
    array arr = { .a = 0.1, .b = 0.2, .c = 0.3, };
    printf("arr = [%f, %f, %f]\n", arr.a, arr.b, arr.c);

    return 0;
}


