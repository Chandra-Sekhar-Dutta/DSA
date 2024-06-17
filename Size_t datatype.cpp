#include <stdio.h>
#include <stddef.h> // Include the header file for size_t

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]); // Get the size of the array

    printf("The array contains %zu elements.\n", array_size); // %zu is the format specifier for size_t

    printf("The array elements are: ");
    for (size_t i = 0; i < array_size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}

