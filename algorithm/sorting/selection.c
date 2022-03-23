#include <stdio.h> 

enum { MAX_SIZE = 5};

size_t find_min_index(int arr[], const size_t start, int end) {
    size_t i;
    size_t min_index = start;

    for (i = start; i < end - 1; i++) {
        if (arr[min_index] > arr[i+1]) {
            min_index = i+1;
        }
    }
    return min_index;
}

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selection_sort(int nums[], int length) {
    size_t i;
    int min_index;
    
    for (i = 0; i < length - 1; i++) {
        min_index = find_min_index(nums, i+1, length);
        if (nums[i] > nums[min_index]) {
            swap(&nums[i], &nums[min_index]);
        }
    }
}

int main(void) {

    size_t i;
    int nums[MAX_SIZE] = {3, 5, 4, 2, 1};

    selection_sort(nums, MAX_SIZE);
    
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}