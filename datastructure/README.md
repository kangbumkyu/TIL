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
7. [트리 Tree](#트리-tree)
8. [그래프 Graph](#그래프-graph)

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
enum { MAX_SIZE = 5 };

int stack[MAX_SIZE];
size_t current_size = 0;

/* 코드 생략 ..... */

void push(int number) {
    assert(current_size < MAX_SIZE);
    stack[current_size++] = number;
}

/* 코드 생략 ..... */

push(1); // {1}
push(2); // {1, 2}
push(3); // {1, 2, 3}
```

<br>

### 스택 삭제

스택 삭제는 배열의 맨 마지막 요소를 제거함으로 시간 복잡도는 O(1)이다.

```
enum { MAX_SIZE = 5 };

int stack[MAX_SIZE];
size_t current_size = 0;

/* 코드 생략 ..... */

int pop(void) {
    assert(current_size > 0);

    return stack[--current_size];
}

/* 코드 생략 ..... */

pop(); // {1, 2}
pop(); // {1}
pop(); // {}
```

<br>

### 스택 검색

스택 안에 어떤 데이터가 들어있는지 검색하려면 위에서 부터 pop을 해야 한다. 만약 찾았으면 pop을 했던 데이터를 다시 push해주면 된다.  
pop을 할 때 O(N), push할 때 O(N) 만큼 걸려서 시간 복잡도는 총 O(2N)이지만 보통 상수는 제거를 하니깐 O(N)이다.

<br><br>

## 큐 (Queue)

가장 먼저 삽입된(enqueue) 데이터가 가장 먼저 삭제되는(dequeue) 자료구조이다.

<br>

### 큐 삽입

큐에 맨 마지막에 삽입하면 된다. 따라서 시간 복잡도는 O(1) 이다.

<br>

### 큐 삭제

큐에 첫 번째 요소를 제거하면 된다. 시간 복잡도는 O(1) 이다.

<br>

### 큐 검색

스택과는 다르게 중간에 데이터를 찾아도 전부 다 dequeue를 하고 다시 enqueue를 해야 한다. 검색 시간 복잡도는 O(N) 이다.

<br><br>

## 연결 리스트 (Linked List)

<br><br>

## 해시 테이블 (Hash Table)

<br><br>

## 트리 (Tree)

<br><br>

## 그래프 (Graph)

