#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

size_t partition(int Arr[], size_t lower, size_t upper)
{
    int pivot = Arr[upper];
    size_t i = lower;

    for (size_t j = lower; j < upper; j++)
    {
        if (Arr[j] < pivot)
        {
            swap(&Arr[i], &Arr[j]);
            i++;
        }
    }
    swap(&Arr[i], &Arr[upper]);
    return i;
}

void quickSort(int Arr[], size_t lower, size_t upper)
{
    if (lower < upper)
    {
        size_t location = partition(Arr, lower, upper);
        if (location > 0)
        {
            quickSort(Arr, lower, location - 1);
        }
        quickSort(Arr, location + 1, upper);
    }
}


void selectionSort(int Arr[], int size) {
    for (size_t i = 1; i < size; i++) {
        int temp = Arr[i];
        int j = i - 1;
        while (j >= 0 && Arr[j] > temp) {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = temp;
    }
}

// ------ Main Function ------ //
int main(void)
{
    int Arr[SIZE] = {4, 2, 0, 6, 1, 8};


    // quickSort(Arr, 0, SIZE - 1);
    selectionSort(Arr, (int)(SIZE));

    for (size_t i = 0; i < SIZE; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    return 0;
}