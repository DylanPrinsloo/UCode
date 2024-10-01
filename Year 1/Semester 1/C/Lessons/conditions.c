#include <stdio.h>
#include <string.h>

int main() {
    // Integer variables
    int x = 6;
    int y = 9;
    int z = 20;

    // String variables (char arrays in C)
    char xa[] = "hello";
    char ya[] = "hi";

    // Relational operators: > < == != >= <=
    // Boolean expressions in C use int (0 for false, non-zero for true)

    // Example comparisons
    // int compare = (x == y);
    // int compare = (strcmp(xa, ya) == 0);

    // Chained comparisons
    // int compare = (x > y && z < y);
    // int compare = (x > y || z < y);
    // int compare = !(x > y || z < y);

    // Using strcmp for string comparison (like ya.equals("hello"))
    int compare = (x > y && z < y) || (x + 7 > y || z < y);

    // Output the result of the boolean expression
    printf("%d\n", compare);

    return 0;
}

