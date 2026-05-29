#include <stdio.h>

#define SIZE 7


void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int flag = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}

int main(void) {
    int arr[SIZE] = {4, 3, 6, 1, 5, 2, 2};

    for (int i = 0; i < (int)(SIZE); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    bubbleSort(arr, SIZE);

    for (int i = 0; i < (int)(SIZE); i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}