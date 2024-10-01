#include <stdio.h>

// Define a struct for Animal with function pointers
typedef struct Animal {
    void (*makeSound)(); // Function pointer for makeSound
    void (*move)();      // Function pointer for move
} Animal;

// Implementation for Dog
void dogMakeSound() {
    printf("Woof!\n");
}

void dogMove() {
    printf("The dog runs.\n");
}

// Implementation for Cat
void catMakeSound() {
    printf("Meow!\n");
}

void catMove() {
    printf("The cat sneaks.\n");
}

// Main function to demonstrate the use of interfaces
int main() {
    // Creating instances of Dog and Cat
    Animal dog = { dogMakeSound, dogMove }; // Initialize Dog
    Animal cat = { catMakeSound, catMove }; // Initialize Cat

    // Calling interface methods
    dog.makeSound(); // Call Dog's makeSound
    dog.move();      // Call Dog's move

    cat.makeSound(); // Call Cat's makeSound
    cat.move();      // Call Cat's move

    return 0;
}
