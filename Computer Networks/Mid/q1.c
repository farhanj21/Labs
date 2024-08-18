#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    FILE *inFile, *outFile;
    int arr[MAX_SIZE];
    int n;
    int i;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        perror("Error Opening Output File");
        return 1;
    }

    n = 0;
    while (fscanf(inFile, "%d", &arr[n]) == 1)
     {
        n++;
        if (n == MAX_SIZE) {
            fclose(inFile);
            return 1;
        }
    }
    fclose(inFile);

    bubbleSort(arr, n);

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        perror("Error Opening Output File");
        return 1;
    }

    for (i = 0; i< n; i++) {
        fprintf(outFile, "%d\n", arr[i]);
    }
    fclose(outFile);
    
    printf("Sorted integers have been written to Output.txt\n");

    return 0; 
}
