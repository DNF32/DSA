#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
  int value;
  int key;
  node_t *next;
  node_t *prev;
};

typedef struct hashmap hash_t;
struct hashmap {
  node_t **array;
  int capacity;
  int load;
};

hash_t *init_map(int capacity) {
  hash_t *map = (hash_t*)malloc(sizeof(hash_t));
  if (map == NULL) {
    printf("Failed to initialize hashmap insidi init\n");
    return NULL;
  }
  map->capacity = capacity;
  map->array = malloc(capacity * sizeof(node_t *));
  if (map->array==NULL) {
    printf("Failed to initialize array\n");
    return NULL;
  }
  // init slots to null pointer
  for (int i = 0; i < capacity; i++) {
    map->array[i] = NULL;
  }
  return map;
}

int hashfunc(int key, int capacity) { return key % (capacity - 1); }

void insert_first_first(hash_t *map, int key, int value) {
  int index = hashfunc(key, map->capacity);

  node_t *list = map->array[index];
// if the index is empty
  if (list == NULL) {
    node_t *head = malloc(sizeof(node_t));
    if (head == NULL) {
      return;
    }
    head->key = key;
    head->value = value;
    head->next = NULL;

    map->array[index] = head;
    return;
  }

  // transverse the tree to see if the key is there
  node_t *head = list;
  while (head != NULL) {
    if (head->key == key) {
      head->value = value;
      return;
    }
    head = head->next;
  }

  // Init new head
  node_t *new_head = malloc(sizeof(node_t));
  if (new_head == NULL) {
    return;
  }
  new_head->key = key;
  new_head->value = value;
  new_head->next = list;
  //
  list->prev = new_head;

  map->array[index] = new_head;
}
void print_map(hash_t *map) {
  for (int i = 0; i < map->capacity; i++) {
    node_t *list = map->array[i];
    printf("Index %d: ", i);
    while (list != NULL) {
      printf("(Key: %d, Value: %d) -> ", list->key, list->value);
      list = list->next;
    }
    printf("NULL\n");
  }
}
int main(void) {
  hash_t *map = init_map(10);
  if (map == NULL) {
    printf("Failed to initialize hashmap\n");
    return 1;
  }

  insert_first(map, 0, 2);
  insert_first(map, 10000, -100);
  insert_first(map, 46, 1);
  insert_first(map, 45, 5);

  print_map(map);
}
