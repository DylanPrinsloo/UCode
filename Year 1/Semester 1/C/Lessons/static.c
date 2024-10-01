#include <stdio.h>

// Static function (similar to static method in Java)
static void this_is_static() {
    printf("Hello\n");
}

// Non-static function (simulated by normal function in C)
void this_is_not_static() {
    printf("Hello\n");
}

int main() {
    // Calling the static function (similar to how you'd call it in Java)
    this_is_static();

    // Calling the non-static function
    this_is_not_static();

    return 0;
}


