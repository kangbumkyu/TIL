#include <stdio.h>
#include <assert.h>

enum
{
    MAX_SIZE = 8
};
int arr[MAX_SIZE];
int arr_count;

void insert_at(size_t index, int number)
{
    size_t i;

    assert(index <= arr_count);
    assert(arr_count < MAX_SIZE);

    for (i = arr_count; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr_count++;
    arr[index] = number;
}

void remove_at(size_t index)
{
    size_t i;

    assert(index < arr_count);

    arr_count--;
    for (i = index; i < arr_count; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int find_index_of(int number)
{
    size_t i;

    for (i = 0; i < arr_count; i++)
    {
        if (arr[i] == number)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    size_t i = 0;

    insert_at(0, 0);
    insert_at(1, 1);
    insert_at(2, 2);
    insert_at(3, 3);
    insert_at(4, 4);
    insert_at(5, 5);
    insert_at(6, 6);
    insert_at(0, 7);
    remove_at(0);

    for (i = 0; i < arr_count; i++)
    {
        printf("%d\n", arr[i]);
    }

    printf("%d\n", find_index_of(6));
    printf("%d\n", find_index_of(10));

    return 0;
}