#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    if (arr == NULL || left < 0 || right < 0 || left >= right) {
        printf("Error: Invalid input parameters for merge function.\n");
        return;
    }

    int i, j, k;
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    int leftArray[sizeLeft], rightArray[sizeRight];

    for (i = 0; i < sizeLeft; i++)
        leftArray[i] = arr[left + i];
    for (j = 0; j < sizeRight; j++)
        rightArray[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < sizeLeft && j < sizeRight) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < sizeLeft) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < sizeRight) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (arr == NULL || left < 0 || right < 0 || left > right) {
        printf("Error: Invalid input parameters for mergeSort function.\n");
        return;
    }

    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    if (arrSize <= 0) {
        printf("Error: Array size should be positive.\n");
        return EXIT_FAILURE;
    }

    printf("Given array is \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("\nSorted array is \n");
    printArray(arr, arrSize);

    return EXIT_SUCCESS;
}
