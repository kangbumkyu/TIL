#include <stdio.h>

enum { MAX_SIZE = 5};

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void insertion_sort(int nums[], int length) {
    size_t i, j;
    
    for (i = 1; i < length; i++) {
        for (j = 0; j < i; j++) {
            if (nums[j] > nums[i]) {
                swap(&nums[j], &nums[i]);
            }
        }
    }
} 

int main(void) {
    size_t i;
    int nums[MAX_SIZE] = {5, 3, 2, 4, 1};
    
    insertion_sort(nums, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}