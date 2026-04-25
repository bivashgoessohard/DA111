/*
Here I will implement the bubble sort algorithm
Time Complexity : O(n^2) worst case scenario
                : O(n) if the array is already sorted(best case)
*/


#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort algorithm function
void bubble_sort(int *arr, int n) {
    // Bubble sort algorithm
    for (int i = 0; i < n-1; i++) {
        int flag = 0;
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("No swap performed in pass %d. Exiting Early.\n", i + 1);
            break;
        }
    }
}

int main() {
    int n;

    // Take number of elements of the array from user
    printf("Enter the number of elements: ");

    // Validate the input
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Initialize the array
    int *arr = malloc(n * sizeof *arr);

    // Check for memory allocation
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Take inputs of the elements of the array
    for (int i = 0; i < n; i++) {
        printf("Enter element %d (index %d): ", i+1, i);
        if(scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            free(arr);
            return 1;
        }
    }

    // Print the array before sorting
    printf("====Array Before Sorting====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if( i < n-1) {
            printf(", ");
        } else {
            printf("]\n");
        }
    }

    // Call bubble sort algorithm function

    bubble_sort(arr, n);

    // Print the array After sorting
    printf("====Array After Sorting====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if( i < n-1) {
            printf(", ");
        } else {
            printf("]\n");
        }
    }

    free(arr);

    return 0;
}
