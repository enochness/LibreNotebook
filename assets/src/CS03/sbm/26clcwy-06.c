#include <stdio.h>

int main() {
    char name[10], fullName[30], alp;
    int age;
    double date;

    printf("Full Name: ");
    fgets(fullName, 30, stdin);
    printf("First Name: ");
    scanf("%s", name); // No ampersand here
    printf("Age: ");
    scanf("%d", &age); // You need this ampersand!
    printf("Date: ");
    scanf("%lf", &date); // %lf not %f
    printf("Alphabet: ");
    scanf(" %c", &alp); // You need the space in front of %c!

    printf("Hi %s, today is %f\n", name, date);
    printf("Your full name is %s", fullName);
    printf("You are %d years old and you chose %c!\n", age, alp);

    return 0;
}


