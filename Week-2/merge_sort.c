#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int lower, int mid, int upper) {
    int i = lower;
    int j = mid + 1;
    int k = 0;
    int *temp = malloc((upper - lower + 1) * sizeof(int));

    while (i <= mid && j <= upper) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= upper) {
        temp[k++] = arr[j++];
    }

    for (int k = 0; k < upper - lower + 1; k++) {
        arr[lower + k] = temp[k];
    }

    free(temp);
}


void mergeSort(int *arr, int lower, int upper) {
    if (lower >= upper)
        return;
    int mid = (lower + upper) / 2;

    mergeSort(arr, lower, mid);
    mergeSort(arr, mid + 1, upper);
    merge(arr, lower, mid, upper);
}


int main(void) {
    int arr[7] = {1, 3, 6, 2, 3, 4, 1};

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    mergeSort(arr, 0, 6);

    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}