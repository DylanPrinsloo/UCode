#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256 // Define a maximum size for our hash table

// Define a structure for a HashMap entry
typedef struct Entry {
    char key;
    int value;
    struct Entry* next; // For handling collisions using linked list
} Entry;

// Define a HashMap
typedef struct HashMap {
    Entry* table[MAX_SIZE]; // Array of pointers to Entry
} HashMap;

// Function to create a new HashMap
HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < MAX_SIZE; i++) {
        map->table[i] = NULL; // Initialize the table
    }
    return map;
}

// Hash function
unsigned int hash(char key) {
    return (unsigned int)key % MAX_SIZE; // Simple hash function
}

// Function to insert key-value pair into HashMap
void put(HashMap* map, char key, int value) {
    unsigned int index = hash(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = map->table[index]; // Insert at the beginning
    map->table[index] = newEntry; // Update the table
}

// Function to get a value from HashMap
int get(HashMap* map, char key) {
    unsigned int index = hash(key);
    Entry* current = map->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // Key found
        }
        current = current->next; // Move to the next entry
    }
    return -1; // Key not found
}

// Function to check if a key exists in HashMap
int containsKey(HashMap* map, char key) {
    return get(map, key) != -1; // Check if key exists
}

// Function to count character occurrences in a string
void countCharacters(const char* str) {
    HashMap* map = createHashMap(); // Create a new HashMap
    for (int i = 0; i < strlen(str); i++) {
        char x = str[i];
        if (containsKey(map, x)) {
            int oldValue = get(map, x);
            put(map, x, oldValue + 1); // Update value
        } else {
            put(map, x, 1); // New character
        }
    }

    // Print the results
    for (int i = 0; i < MAX_SIZE; i++) {
        Entry* current = map->table[i];
        while (current != NULL) {
            printf("Character: '%c', Count: %d\n", current->key, current->value);
            current = current->next; // Move to the next entry
        }
    }

    free(map); // Free memory
}

int main() {
    // Create a simple HashMap and add some key-value pairs
    HashMap* map = createHashMap();
    put(map, 'T', 200);
    put(map, 'I', 888);
    put(map, 'D', 1);
    
    // Check existence and print value
    printf("Value for 'T': %d\n", get(map, 'T')); // Should print 200
    printf("Value for 'A': %d\n", get(map, 'A')); // Should print -1 (not found)

    // Count characters in a string
    const char* str = "Hello my name is Dylan and I am cool";
    countCharacters(str);

    // Free allocated memory (not shown for simplicity)
    free(map);
    
    return 0;
}
