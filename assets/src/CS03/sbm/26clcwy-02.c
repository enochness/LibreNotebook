#include <stdio.h>

int main() {
    int age = 123;
    double gpa = 3.14;
    char name[] = "Enoch";

    printf("%s is %d years old.\n", name, age);
    printf("He has a GPA of %f and a letter grade of %c\n", gpa, 'A');
    printf("%s also loves math. For example...\n", name);
    printf("%f / %d = %f\n", 1.0, 5, 1.0 / 5);

    return 0;
}


