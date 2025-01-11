#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node node_t;
struct node {
    node_t *right;
    node_t *left;
    int data;
};

// Function prototypes
void insertion(node_t *tree, int value);
int size(node_t *tree);
int* inorder(node_t *tree);
void print_inorder(node_t *tree);
void free_tree(node_t *node);
#endif
