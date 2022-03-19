#include <stdio.h>
#include <assert.h>

enum
{
    MAX_SIZE = 4
};
enum
{
    FALSE = 0,
    TRUE = 1,
};

int queue[MAX_SIZE];
size_t queue_count = 0;
size_t front;
size_t rear;

int is_empty()
{
    return queue_count == 0;
}

void enqueue(int number)
{
    assert(queue_count < MAX_SIZE);

    queue[rear] = number;
    rear = (rear + 1) % MAX_SIZE;
    queue_count++;
}

int dequeue(void)
{
    int ret;

    assert(is_empty() == FALSE);

    ret = queue[front];
    queue_count--;
    front = (front + 1) % MAX_SIZE;

    return ret;
}

int main(void)
{
    size_t i;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();

    for (i = 0; i < queue_count; i++)
    {
        printf("%d\n", queue[i]);
    }

    return 0;
}