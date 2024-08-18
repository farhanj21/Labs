#include <stdio.h>

int main() {
    FILE *file;
    char buffer[256];

    file = fopen("InputFile.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
