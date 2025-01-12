typedef struct node node_t;

struct node {
  int value;
  int key;
  node_t *next;
};

typedef struct hashmap hash_t;
struct hashmap {
  node_t *array[100];
  int load;
};

hash_t init_map() {}
