#include <stdio.h>

int main() {
    // For loop
    int arr[] = {1, 4, 5, 7, 8, 5, 10};
    int arrLength = sizeof(arr) / sizeof(arr[0]); // Calculate the length of the array

    for (int i = 0; i < arrLength; i++) { // Use < instead of <=
        printf("%d\n", arr[i]); // Print the element instead of index

        if (arr[i] == 5) {
            printf("Found 5 at index %d\n", i);
        }
    }

    // New loop
    char* names[5]; // Array of string pointers
    int count = 0;

    // Initialize names with NULL to avoid garbage values
    for (int i = 0; i < 5; i++) {
        names[i] = NULL;
    }

    for (int i = 0; i < 5; i++) {
        printf("Input name %d: ", i + 1);
        names[i] = (char*)malloc(100 * sizeof(char)); // Allocate memory for each name
        scanf("%s", names[i]); // Read a string input
    }

    // Count the index
    for (int i = 0; i < 5; i++) {
        printf("%s %d\n", names[i], i);
    }

    // While loop
    int x = 0;
    while (x != 10) {
        printf("Type 10\n");
        printf("Input a number: ");
        scanf("%d", &x);
    }

    // Do while loop
    do {
        printf("Input a number: ");
        scanf("%d", &x);
    } while (x != 10);

    // Free allocated memory
    for (int i = 0; i < 5; i++) {
        free(names[i]); // Free allocated memory for each name
    }

    return 0;
}



