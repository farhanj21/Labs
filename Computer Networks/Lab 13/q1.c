#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLength 100
#define maxLine 1000

void reverseStr(char *str) 
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char word[maxLength];
    printf("Enter the word to search for and reverse: ");
    scanf("%s", word);

    FILE *inFile = fopen("input.txt", "r");
    FILE *outFile = fopen("output.txt", "w");
    

    char line[maxLine];
    int wordCount = 0;
    while (fgets(line, sizeof(line), inFile)) {
        char *position = line;
        while ((position = strstr(position, word)) != NULL) {
            reverseStr(word);
            fputs(word, outFile);
            position += strlen(word);
            wordCount++;
        }
        fputs(line, outFile);
    }

    printf("Total occurrences of '%s' reversed and written to output.txt: %d\n", word, wordCount);

    fclose(inFile);
    fclose(outFile);

    return 0;
}

