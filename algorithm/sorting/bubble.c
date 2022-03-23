#include <stdio.h>

enum { MAX_SIZE = 5};

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubble_sort(int nums[], int length) {
    size_t i;
    size_t j;

    for (i = 0; i < length; i++) {
        for (j = 1; j < length - i; j++) {
            if (nums[j-1] > nums[j]) {
                swap(&nums[j-1], &nums[j]);
            }
        }
    }
}

int main(void) {
    size_t i;
    int nums[MAX_SIZE] = {3, 2, 5, 1, 4};

    bubble_sort(nums, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", nums[i]);
    }

    return 0;

}