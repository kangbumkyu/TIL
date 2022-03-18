#include <stdio.h>
#include <assert.h>

enum
{
    MAX_SIZE = 5
};
enum
{
    FALSE = 0,
    TRUE = 1
};

int is_empty(size_t size)
{
    return size == 0;
}

void push(int arr[], size_t *size, int number)
{
    assert(*size < MAX_SIZE);
    arr[(*size)++] = number;
}

int pop(int arr[], size_t *size)
{
    assert(is_empty(*size) == FALSE);

    return arr[--(*size)];
}

int find(int arr[], size_t size, int number)
{
    int temp;
    int temp_stack[MAX_SIZE];
    int ret = FALSE;
    size_t temp_current_size = 0;

    // stack이 empty 될 때 까지 pop하기
    while (is_empty(size) == FALSE)
    {
        temp = pop(arr, &size);
        push(temp_stack, &temp_current_size, temp);

        if (temp == number)
        {
            ret = TRUE;
            break;
        }
    }

    // pop된 데이터를 다시 stack에 push하기
    while (is_empty(temp_current_size) == FALSE)
    {
        temp = pop(temp_stack, &temp_current_size);
        push(arr, &size, temp);
    }

    return ret;
}

int main(void)
{
    size_t i;
    int stack[MAX_SIZE];
    size_t current_size = 0;

    push(stack, &current_size, 0);
    push(stack, &current_size, 1);
    push(stack, &current_size, 2);
    push(stack, &current_size, 3);
    push(stack, &current_size, 4);
    pop(stack, &current_size);
    pop(stack, &current_size);
    pop(stack, &current_size);

    for (i = 0; i < current_size; i++)
    {
        printf("%d\n", stack[i]);
    }

    printf("%d\n", find(stack, current_size, 1));
    printf("%d\n", find(stack, current_size, 10));

    return 0;
}