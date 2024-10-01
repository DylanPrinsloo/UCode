#include <stdio.h>
#include <string.h>

// Function to sort a portion of an array (similar to Arrays.sort(x, 1, 7))
void sort(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = i + 1; j < end; j++) {
            if (arr[i] > arr[j]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    // Array of strings
    char* newArr[] = {"Dylan", "Marco", "Ashely", "Josephine"};
    printf("Length of newArr: %lu\n", sizeof(newArr) / sizeof(newArr[0]));

    // Array of integers
    int number[] = {2, 4, 7, 8, 10};
    int a = number[3];
    printf("The element at index 3: %d\n", a);

    // Another integer array
    int x[] = {-88, 54, 43, 23, 25, 88};

    // Sort the array from index 1 to 6 (like Java's Arrays.sort)
    sort(x, 1, 6);  // Sorting from index 1 to 6 (end is exclusive)

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        printf("%d,", x[i]);
    }
    printf("\n");

    return 0;
}

