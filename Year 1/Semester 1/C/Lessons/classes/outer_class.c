#include <stdio.h>
#include <string.h>

// Outer class equivalent (struct)
typedef struct {
    char outerField[50];
} OuterClass;

// Inner class equivalent (struct)
typedef struct {
    char innerField[50];
    OuterClass *outer;  // Reference to the outer class
} InnerClass;

// Method to display the outer and inner fields
void display(InnerClass *inner) {
    printf("Outer field: %s\n", inner->outer->outerField);
    printf("Inner field: %s\n", inner->innerField);
}

// Method equivalent to outerMethod()
void outerMethod(OuterClass *outer) {
    InnerClass inner;
    inner.outer = outer;  // Link to the outer class
    strcpy(inner.innerField, "Inner field");

    display(&inner);  // Calling inner class's display method
}

int main() {
    // Creating an instance of the outer class
    OuterClass outer;
    strcpy(outer.outerField, "Outer field");

    // Calling the outer method, which uses the inner class
    outerMethod(&outer);

    return 0;
}

