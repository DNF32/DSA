#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
  int value;
  node_t *next;
};

// Initialize a tree
node_t *initialize_head(int value) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  if (node == NULL) {
    printf("Memory allocation failed");
  }
  node->value = value;
  node->next = NULL;
  return node;
}

// Add a node to tree
void insert_last(node_t *head, int value) {
  while (head->next != NULL) {
    head = head->next;
  }
  node_t *node = (node_t *)malloc(sizeof(node_t));
  if (node == NULL) {
    printf("Memory allocation failed");
  }
  node->value = value;
  node->next = NULL;

  head->next = node;
}

void insert_first(node_t **head, int value) {
  node_t *new_head = (node_t *)malloc(sizeof(node_t));
  if (new_head == NULL) {
    printf("Memory allocation failed");
  }
  new_head->value = value;
  new_head->next = *head;
  *head = new_head;
};

void delete(node_t **head, int value) {
  if (*head == NULL) {
    return;
  }

  node_t *current = *head;
  node_t *prev = NULL;
  if (current->value == value) {
    *head = current->next;
    free(current);
    return;
  }
  while (current != NULL) {
    if (current->value == value) {
      prev->next = current->next;
      free(current);
      break;
    }
    prev = current;
    current = current->next;
  }
}

// Seach for element in tree
int search(node_t *head, int value) {
  while (head != NULL) {
    if (head->value == value)
      return 1;
    head = head->next;
  }
  return 0;
}

int len(node_t *head) {
  int count = 0;
  while (head != NULL) {
    count += 1;
    head = head->next;
  }
  return count;
};

void transverse_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

void free_list(node_t **head) {
  node_t *current = *head;
  node_t *prev;
  while (current != NULL) {
    prev = current;
    current = current->next;
    free(prev);
  }
  *head = NULL;
}
// Free whole tree

int main() {
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  node_t *head = malloc(sizeof(node_t));
  head->value = 1;
  head->next = malloc(sizeof(node_t));
  head->next->value = 2;
  head->next->next = malloc(sizeof(node_t));
  head->next->next->value = 3;
  head->next->next->next = malloc(sizeof(node_t));
  head->next->next->next->value = 4;
  head->next->next->next->next = malloc(sizeof(node_t));
  head->next->next->next->next->value = 5;
  head->next->next->next->next->next = NULL;

  // Print the original linked list
  node_t *current = head;
  printf("Original linked list: ");
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");

  // Delete the node with value 3
  delete (head, 3);

  // Print the linked list after deletion
  current = head;
  printf("Linked list after deletion: ");
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");

  return 0;
}
