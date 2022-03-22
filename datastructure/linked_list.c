#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct node node_t;

typedef struct node {
    int value;
    node_t* next;
} node_t;

void print_list(node_t* node) {

    node_t* temp = node;

    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

void destroy_list(node_t* node) {
    node_t* p = node;
    while (p != NULL) {
        node_t* temp = p->next;
        free(p);
        p = temp;
    }
}

void insert_front(node_t** node, int n) {
    node_t* new_node;

    new_node = malloc(sizeof(node_t));
    new_node->value = n;

    new_node->next = *node;
    *node = new_node;
}

void remove_node(node_t** node, int n) {
    node_t** pp = node;

    while (*pp != NULL) {
        if ((*pp)->value == n) {
            node_t* temp = *pp;
            *pp = (*pp)->next;
            free(temp);
            break;
        }
        pp = &(*pp)->next;
    }
}

int main(void) {
    node_t* head = NULL;

    insert_front(&head, 3);
    insert_front(&head, 2);
    insert_front(&head, 1);
    print_list(head);
    printf("%d\n", head->value);
    remove_node(&head, 2);
    print_list(head);

    destroy_list(head);
    head = NULL;

    return 0;
}