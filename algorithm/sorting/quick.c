#include <stdio.h>

enum { MAX_SIZE = 8 };

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], size_t left, size_t right) {
    size_t i = left - 1;
    size_t j;
    int pivot = arr[right];
    int pivot_index;
    
    for (j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    pivot_index = i + 1;
    swap(&arr[pivot_index], &arr[right]);

    return pivot_index;
}

void quick_sort(int arr[],  size_t start, size_t end) {
    int pivot_index;

    if (start >= end) {
        return;
    }

    pivot_index = partition(arr, start, end);

    quick_sort(arr, start, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, end);

}


int main(void) {

    size_t i;
    int nums[MAX_SIZE] = {1, 8, 2, 4, 6, 7, 3, 5};

    quick_sort(nums, 0, MAX_SIZE-1);

    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
