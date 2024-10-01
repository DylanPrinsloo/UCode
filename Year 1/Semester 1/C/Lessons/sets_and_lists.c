#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define a maximum size for our set

// Function prototypes
int contains(int *set, int size, int value);
void add(int *set, int *size, int value);
void printSet(int *set, int size);

int main() {
    int set[MAX_SIZE]; // Array to hold the set elements
    int size = 0;      // Current size of the set

    // Adding elements to the set
    add(set, &size, 5);
    add(set, &size, 4);
    add(set, &size, 1);
    add(set, &size, 5); // Attempting to add a duplicate

    // Check for existence of an element
    int valueToCheck = 0; // Change this to 5 to check for existence
    if (contains(set, size, valueToCheck)) {
        printf("%d is in the set.\n", valueToCheck);
    } else {
        printf("%d is not in the set.\n", valueToCheck);
    }

    // Print the set
    printSet(set, size);

    return 0; // Indicate successful completion
}

// Function to check if a value is in the set
int contains(int *set, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) {
            return 1; // Return true (1) if found
        }
    }
    return 0; // Return false (0) if not found
}

// Function to add a value to the set
void add(int *set, int *size, int value) {
    if (!contains(set, *size, value)) { // Only add if not already in the set
        set[*size] = value;
        (*size)++;
    }
}

// Function to print the set
void printSet(int *set, int size) {
    printf("Set elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}
