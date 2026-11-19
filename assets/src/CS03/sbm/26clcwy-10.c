#include <stdio.h>

void helloUser(char name[]) {
    printf("Hello %s\n", name);
}

int main() {
    char name[20];
    printf("Your name: ");
    scanf("%s", name);
    helloUser(name);

    return 0;
}


