#include <stdio.h>
#include <stdlib.h>
typedef struct node node_t;

struct node {
  node_t *right;
  node_t *left;
  int data;
};

void insertion(node_t *tree, int value) {
  node_t *subtree = tree;
  node_t *parent = NULL;
  int nonleaf = 1;
  while (nonleaf) {
    parent = subtree;

    if (subtree->data >= value) {
      subtree = subtree->left;
      if (!subtree) {
        nonleaf = 0;
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->left = NULL;
        node->right = NULL;
        node->data = value;

        parent->left = node;
      }
    }

    else {
      subtree = subtree->right;
      if (!subtree) {
        nonleaf = 0;
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->left = NULL;
        node->right = NULL;
        node->data = value;

        parent->right = node;
      }
    }
  }
}

// Function to print the tree (in-order traversal) tradicional way
void print_inorder(node_t *tree) {
  if (tree == NULL)
    return;
  print_inorder(tree->left);
  printf("%d ", tree->data);
  print_inorder(tree->right);
}

int size(node_t *tree){
  if(tree == NULL)
    return 0;
  else
    return 1 + size(tree->left) + size(tree->right);
}

// Function to print the tree (in-order traversal) using while loops and manual stack implementation
int* inorder(node_t *tree) {
    if(tree == NULL)
      return NULL;
    int dim = size(tree);
    int *array = (int*)malloc(dim * sizeof(int));
    if (array == NULL) {
        printf("Error: memory allocation failed\n");
        return NULL;
    }
    node_t *current = tree;
    node_t *stack[100];
    int top = -1;
    int counter = -1;  // Start from -1 as in the original code
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        array[++counter] = current->data;  // Increment counter before assigning
        current = current->right;
    }
    return array;
}

// Helper function to free the tree
void free_tree(node_t *node) {
  if (node == NULL)
    return;
  free_tree(node->left);
  free_tree(node->right);
  free(node);
}
