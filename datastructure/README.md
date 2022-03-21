# 자료구조

자료구조란 컴퓨터에서 여러 자료를 체계적으로 저장하는 방법을 의미한다.  
다양한 자료구조가 존재하기 때문에 현재 자신이 풀어야 하는 문제에 맞는 자료구조를 선택하면 효율적으로 문제를 해결할 수 있다.
<br><br>

### 효율적인 자료구조

어떤 자료구조가 효율적인지는(여기선 시간복잡도) 빅오 표기법을 통해서 파악할 수 있다. <br>
예) 데이터를 검색하는데 시간복잡도가 O(N^2)인 자료구조는 시간복잡도가 O(N)인 자료구조 보다 느리다.

<br><br>

## Table of Contents

0. [Intro](#자료구조)
1. [배열 Array](#배열-array)
2. [스택 Stack](#스택-stack)
3. [큐 Queue](#큐-queue)
4. [연결 리스트 Linked List](#연결-리스트-linked-list)
5. [해시 테이블 Hash Table](#해시-테이블-hash-table)
6. [트리 Tree](#트리-tree)
7. [그래프 Graph](#그래프-graph)

## 배열 (Array)

배열은 여러 개의 자료를 하나의 메모리 공간 안에 순서대로 저장해 놓는 구조이다. 각각의 데이터는 index로 접근이 가능하다.

<img width="400" alt="스크린샷 2022-03-18 오후 1 19 38" src="https://user-images.githubusercontent.com/42689355/158942098-0299ea34-04d8-4f4f-82df-563b53dd620d.png">

<br>

### 배열 삽입

[소스코드](https://github.com/kangbumkyu/TIL/blob/main/datastructure/array.c#L11)

데이터를 배열에 삽입하려면 삽입할 위치의 요소부터 마지막 요소까지 한칸씩 밀고 삽입해야 한다. 따라서 시간복잡도는 O(N)이다.<br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 23 12" src="https://user-images.githubusercontent.com/42689355/158942489-58b06eb7-1980-4c23-9b1a-39cb8cb2cfa4.png"><br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 20 48" src="https://user-images.githubusercontent.com/42689355/158942275-37da31b2-d014-4e4d-9c1d-15f78ee43c57.png">

```
int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6};
size_t arr_count = 6;

/* 코드 생략..... */

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

/* 코드 생략..... */

insert_at(1, 10); // {1, 10, 2, 3, 4, 5, 6};
insert_at(7, 12); // {1, 10, 2, 3, 4, 5, 6, 12};


```

<br>

### 배열 삭제

[소스코드](https://github.com/kangbumkyu/TIL/blob/main/datastructure/array.c#L26)

배열에서 데이터를 삭제하려면 삭제할 인덱스 다음 요소부터 끝까지 앞으로 한 칸씩 이동해주면 된다. 데이터를 하나씩 앞으로 이동시켜야 함으로 시간복잡도는 O(N)이다.<br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 27 33" src="https://user-images.githubusercontent.com/42689355/158942885-254b439a-ea79-4bf7-9cc6-983f07180a5a.png"><br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 28 59" src="https://user-images.githubusercontent.com/42689355/158943046-6e291812-df8e-4941-ab43-1e6c67380391.png">

```
int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7};
size_t arr_count = 7;

/* 코드 생략..... */


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

/* 코드 생략..... */

remove_at(2); // {1, 2, 4, 5, 6, 7}
remove_at(0); // {2, 4, 5, 6, 7}




```

<br>

### 배열 검색

[소스코드](https://github.com/kangbumkyu/TIL/blob/main/datastructure/array.c#L39)

배열에서 데이터를 검색하려면 배열의 첫번째 요소부터 끝까지 차례대로 방문하면서 찾고자 하는 값이 있는지 확인하면 된다. 첫번째 요소부터 최대 끝까지 방문해야 함으로 시간 복잡도는 O(N)이다.<br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 33 52" src="https://user-images.githubusercontent.com/42689355/158943552-4c992bde-6566-4813-95a2-29973ffb2d39.png"><br>

<img width="400" alt="스크린샷 2022-03-18 오후 2 34 35" src="https://user-images.githubusercontent.com/42689355/158943606-e8fbca5b-21a6-4ad3-9409-c80ece55e2e1.png">

```
int arr[MAX_SIZE] = {1, 2, 3, 4, 5, 6};
size_t arr_count = 6;

/* 코드 생략..... */


size_t find_index_of(int number) {
    size_t i;
    for (i = 0; i < arr_count; i++) {
        if (arr[i] == number) {
            return i;
        }
    }
    return -1;
}

/* 코드 생략..... */


find_index_of(5);  // 4 리턴
find_index_of(10); // -1 리턴

```

<br>

### 배열 접근

배열은 데이터가 메모리 안에 순서대로 저장되어 있기 때문에 접근 하고자 하는 데이터의 인덱스를 알고 있으면 한 번에 접근할 수 있다. 따라서 시간 복잡도는 O(1) 이다.

```
int arr[MAX_SIZE] = {1, 2, 3, 4, 5};

printf("%d", arr[3]); // 4

arr[3] = 6;

printf("%d", arr[3]); // 6
```

<br><br>

## 스택 (Stack)

가장 먼저 삽입(Push)된 데이터가 제일 마지막에 삭제(Pop)되는 자료구조이다.

<br><br>

### 스택 삽입

배열의 맨 마지막 위치에 삽입하면 되기 때문에 시간 복잡도는 O(1)이다.

```

/* 코드 생략 ..... */

void push(int arr[], size_t *size, int number)
{
    assert(*size < MAX_SIZE);
    arr[(*size)++] = number;
}

/* 코드 생략 ..... */

push(stack, &current_size, 1); // {1}
push(stack, &current_size, 2); // {1, 2}
push(stack, &current_size, 3); // {1, 2, 3}
```

<br>

### 스택 삭제

스택 삭제는 배열의 맨 마지막 요소를 제거함으로 시간 복잡도는 O(1)이다.

```
/* 코드 생략 ..... */

int pop(int arr[], size_t *size)
{
    assert(is_empty(*size) == FALSE);

    return arr[--(*size)];
}

/* 코드 생략 ..... */

pop(stack, &current_size); // {1, 2}
pop(stack, &current_size); // {1}
pop(stack, &current_size); // {}
```

<br>

### 스택 검색

스택 안에 어떤 데이터가 들어있는지 검색하려면 위에서 부터 pop을 해야 한다. 만약 찾았으면 pop을 했던 데이터를 다시 push해주면 된다.  
pop을 할 때 O(N), push할 때 O(N) 만큼 걸려서 시간 복잡도는 총 O(2N)이지만 보통 상수는 제거를 하니깐 O(N)이다.

```
/* 코드 생략 ..... */

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

/* 코드 생략 ..... */

printf("%d\n", find(stack, current_size, 1));
printf("%d\n", find(stack, current_size, 10));

```

<br><br>

## 큐 (Queue)

가장 먼저 삽입된(enqueue) 데이터가 가장 먼저 삭제되는(dequeue) 자료구조이다.

<br>

### 큐 삽입

큐에 맨 마지막에 삽입하면 된다. 따라서 시간 복잡도는 O(1) 이다.

```
void enqueue(int number)
{
    assert(queue_count < MAX_SIZE);

    queue[rear] = number;
    rear = (rear + 1) % MAX_SIZE;
    queue_count++;
}
```

<br>

### 큐 삭제

큐에 첫 번째 요소를 제거하면 된다. 시간 복잡도는 O(1) 이다.

```
int is_empty()
{
    return queue_count == 0;
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
```

<br>

### 큐 검색

스택과는 다르게 중간에 데이터를 찾아도 전부 다 dequeue를 하고 다시 enqueue를 해야 한다. 검색 시간 복잡도는 O(N) 이다.

<br><br>

## 연결 리스트 (Linked List)

연결 리스트는 배열, 스택, 큐 처럼 데이터가 메모리 공간에 연속적으로 저장되어 있지 않고 여러군데 흩어져서 저장되어 있는 자료구조이다. 이게 가능한 이유는 메모리를 동적으로 할당하기 때문이다. 메모리를 동적으로 할당해서 데이터를 저장한다. 데이터가 저장된 공간을 노드라고 하고, 이 노드끼리 연결이 되어 있다고 해서 연결 리스트라고 부른다.

노드에는 다음에 연결된 노드의 메모리 주소를 저장하는 포인터 변수가 있다. 따라서 노드끼리 연결이 가능해진다. 마지막 노드의 다음 노드는 존재하지 않기 때문에 노드의 주소를 저장하는 포인터 변수엔 NULL이 들어간다.

연결 리스트는 배열이 지닌 한계를 없애고자 사용하는 자료구조다. 따라서 배열의 최대길이가 정해져 있지 않거나 삽입, 삭제가 자주 일어나는 경우 사용한다. (하지만 요즘엔 동적 할당 배열을 자주 사용한다고 한다.)

<br>

### 연결 리스트 삽입

어디에 삽입해야 할 지 알고 있다면 노드를 삽입의 시간 복잡도는 O(1)이다. 배열처럼 다른 요소를 밀(shift) 필요가 없다.

<br>

### 연결 리스트 삭제

삭제할 위치를 알고 있다면 삭제 시간 복잡도는 O(1)이다. 삭제 역시 배열처럼 다른 요소를 당길 필요가 없다.

<br>

### 연결 리스트 검색

연결 리스트에서 검색은 첫 노드(헤드) 부터 찾을 때까지 검색해야 하기 때문에 시간 복잡도는 O(N)이다. 배열은 인덱스로 검색을 했지만 연결 리스트는 노드가 메모리 상에 뿔뿔이 흝어져 있기 때문에 인덱스로 접근은 불가능하고 노드의 다음 주소로 접근해서 데이터를 검색해야 한다.

<br><br>

## 해시 테이블 (Hash Table)

해시 테이블은 어떤 키에 대응되는 값을 키와 같이 저장하는 자료구조이다. 키를 가지고 검색을 하면 값을 시간 복잡도 O(1)으로 가져올 수 있다.

키를 해시 함수에 넣어 얻은 해시값을 가지고 색인을 만들어 해시 테이블(내부적으론 배열)에 저장하면 해시 테이블에서 검색 시간 복잡도가 O(1)이 될 수 있다. (최악은 O(N), 색인 값이 다 동일한 경우)

<br>

### 해시 함수

해시 함수란 임의의 크기를 가진 데이터(입력값)을 고정된 크기의 값으로 출력해주는 함수이다.

- 함수니깐 당연히 입력값이 같으면 출력값이 같다.
- 입력값이 달라도 출력값이 같을 수 있다 (해시 충돌)
- 만일 해시 충돌이 없음을 보장할 수 있는 해시 함수라면, 해시 테이블에 저장할 키를 정수형으로 저장할 수 있어 메모리 공간을 줄일 수 있다.

<br>

### 색인

해시 함수에서 나온 해시값을 가지고 색인으로 변경하여 배열에 저장하는데 사용한다.
색인이 중복되지 않았다면 바로 키에 해당하는 값을 가져올 수 있다.  
색인 중복을 피하기 위해 저장할 개수 \* 2 값에서 그 다음에 오는 소수로 나눴을 때 나머지 값을 색인으로 사용하면 색인이 중복되는걸 어느정도 방지할 수 있다.

- 해시값이 [1, 180402, 4139] 이면, 3 \* 2 다음의 소수인 7로 나누면 색인은 [1, 5, 2] 가 된다.
- 그러면 [min_value, 1, 4139, min_value, min_value, 180402, min_value] 이런식으로 데이터를 저장할 수 있다.
- 색인 충돌이 일어나면 색인 + 1을 해서 저장하거나, 배열안에 요소를 연결리스트 혹은 배열로 저장해서 방지할 수 있다.

<br><br>

## 트리 (Tree)

<br><br>

## 그래프 (Graph)
