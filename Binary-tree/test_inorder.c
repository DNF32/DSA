#include "binary_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Helper function to create a BST from an array
node_t *create_bst(int arr[], int n) {
  node_t *root = NULL;
  for (int i = 0; i < n; i++) {
    if (root == NULL) {
      root = (node_t *)malloc(sizeof(node_t));
      root->data = arr[i];
      root->left = root->right = NULL;
    } else {
      insertion(root, arr[i]);
    }
  }
  return root;
}

// Test function for inorder traversal
void test_inorder(int *expected, int n, node_t *root, const char *test_name) {
  printf("Running test: %s\n", test_name);
  int *result = inorder(root);
  assert(result != NULL);
  for (int i = 0; i < n; i++) {
    assert(result[i] == expected[i]);
  }
  free(result);
  printf("Test passed: %s\n\n", test_name);
}

int main() {
  // Test 1: Empty tree
  {
    node_t *root = NULL;
    int *result = inorder(root);
    assert(result == NULL);
    printf("Test passed: Empty tree\n\n");
  }

  // Test 2: Single node tree
  {
    int arr[] = {5};
    node_t *root = create_bst(arr, 1);
    int expected[] = {5};
    test_inorder(expected, 1, root, "Single node tree");
    free_tree(root);
  }

  // Test 3: Balanced BST
  {
    int arr[] = {4, 2, 6, 1, 3, 5, 7};
    node_t *root = create_bst(arr, 7);
    int expected[] = {1, 2, 3, 4, 5, 6, 7};
    test_inorder(expected, 7, root, "Balanced BST");
    free_tree(root);
  }

  // Test 4: Left-skewed tree
  {
    int arr[] = {5, 4, 3, 2, 1};
    node_t *root = create_bst(arr, 5);
    int expected[] = {1, 2, 3, 4, 5};
    test_inorder(expected, 5, root, "Left-skewed tree");
    free_tree(root);
  }

  // Test 5: Right-skewed tree
  {
    int arr[] = {1, 2, 3, 4, 5};
    node_t *root = create_bst(arr, 5);
    int expected[] = {1, 2, 3, 4, 5};
    test_inorder(expected, 5, root, "Right-skewed tree");
    free_tree(root);
  }

  printf("All tests passed successfully!\n");
  return 0;
}
