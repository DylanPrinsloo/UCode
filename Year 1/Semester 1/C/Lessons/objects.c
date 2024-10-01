#include <stdio.h>

// Function declarations
void second(const char *str, int x);
int third(int x);

int main() {
    // Example string
    const char *h = "Hello";
    // Get the length of the string (not used further)
    int length = 0;
    while (h[length] != '\0') { // Calculate string length
        length++;
    }

    // Call the second function
    second("second method", 4);

    // Calling the third function and printing the result
    printf("%d\n", third(20));

    return 0; // Indicate successful completion
}

// Function to print a string 'x' times
void second(const char *str, int x) {
    for (int i = 0; i < x; i++) {
        printf("%s\n", str);
    }
}

// Function to return x + 2
int third(int x) {
    return x + 2;
}

