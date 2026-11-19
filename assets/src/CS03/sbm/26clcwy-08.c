#include <stdio.h>

int main() {
    int choice;
    printf("Your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Your choice is 1\n");
            break;
        case 2:
            printf("Your choice is 2\n");
            break;
        case 3:
            printf("Your choice is 3\n");
            break;
        default:
            printf("Invalid Option\n");
            break;
    }

    return 0;
}


