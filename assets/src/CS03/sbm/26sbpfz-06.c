#include <stdio.h>

int main() {
    FILE* fptr = fopen("file.txt", "w"); // r, w, a
    fprintf(fptr, "Hello World\n");
    fclose(fptr);

    return 0;
}


