#include <stdio.h>

int main() {
    char scanned[100];  // Buffer to hold the input string

    // Taking input from the user
    printf("Enter a number: ");
    scanf("%s", scanned);  // Read a string input

    // Conversion to integer
    int x = atoi(scanned);  // Convert string to integer

    // Print the scanned input
    printf("\n%s\n", scanned);
    // Optionally, print the converted integer
    printf("Converted integer: %d\n", x);

    return 0;
}
