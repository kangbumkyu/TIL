#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

typedef struct node {
    int value;
    node_t* left;
    node_t* right;
} node_t;

void append(node_t** node, int value) {
    if (*node == NULL) {
        
        node_t* new_node = malloc(sizeof(node_t));
        new_node->value = value;
        *node = new_node;
        return;
    }
    if ((*node)->value >= value) {
        // append left         
        append(&(*node)->left, value);
    } 
    else {
        // append right
        append(&(*node) -> right, value);
    }
}

void destroy(node_t* node) {
    if (node->left != NULL) {
        destroy(node->left);
    }

    if (node->right != NULL) {
        destroy(node->right);
    }    
    free(node);
    node = NULL;
    return;
}

void pre_order_traverse(node_t* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    pre_order_traverse(node->left);
    pre_order_traverse(node->right);
}

void in_order_traverse(node_t* node) {
    if (node == NULL) {
        return;
    }
    in_order_traverse(node->left);
    printf("%d ", node->value);
    in_order_traverse(node->right);
}

void post_order_traverse(node_t* node) {
    if (node == NULL) {
        return;
    }

    post_order_traverse(node->left);
    post_order_traverse(node->right);
    printf("%d ", node->value);
}

int main(void) {

    node_t* root = NULL;
   
    append(&root, 4);
    append(&root, 2);
    append(&root, 5);
    append(&root, 3);
    append(&root, 9);
    append(&root, 8);
    append(&root, 1);
    

    printf("pre order traverse: ");
    pre_order_traverse(root);
    printf("\nin order traverse: ");
    in_order_traverse(root);
    printf("\npost order traverse: ");
    post_order_traverse(root);

    destroy(root);

    return 0;
}