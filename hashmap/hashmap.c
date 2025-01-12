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
  hash_t *map = (hash_t *)malloc(sizeof(hash_t));
  if (map == NULL) {
    return NULL;
  }
  map->capacity = capacity;
  map->array = malloc(capacity * sizeof(node_t *));
  if (map->array) {
    return NULL;
  }
  // init slots to null pointer
  for (int i = 0; i < capacity; i++) {
    map->array[i] = NULL;
  }
  return map;
}

int hashfunc(int key, int capacity) { return key % (capacity - 1); }

void insert(hash_t *map, int key, int value) {
  int index = hashfunc(key, map->capacity);

  node_t *list = map->array[index];

  if (list == NULL) {
    node_t *head = malloc(sizeof(node_t));
    if(head ==NULL){return;}
    head->key = key;
    head->value = value;
    head->next = NULL;

    list = head;
  }
  node_t* head = list;
  while(head!=NULL){
    if(head->key==key){head->value=value;}
    head = head->next;
  }
  // Init new head
  node_t* new_head = malloc(sizeof(node_t));
  new_head->key = key;
  new_head->value = value;
  new_head->next = list;
  // 
  list->prev = new_head;
}
