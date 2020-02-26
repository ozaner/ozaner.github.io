#include <stdio.h>
#include <stdlib.h>
#define BUCKETS 10000

int collisions = 0;
int searches_suc = 0;

// Define node
typedef struct node {
  int data;
  struct node *next;
} node;

node* table[BUCKETS];

node* createNode(int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int hash(int key) {
  return (key % BUCKETS + BUCKETS) % BUCKETS;
}

void insert(int key) {
  int index = hash(key);
  if(table[index] == NULL)
    table[index] = createNode(key);
  else {
    node* ptr = table[index];
    while(ptr->next != NULL) {
      if(ptr->data == key) {
        collisions++;
        return;
      }
      ptr = ptr->next;
    }
    ptr->next = createNode(key);
    collisions++;
  }
}

void search(int key) {
  int index = hash(key);
  node* ptr = table[index];
  while(ptr != NULL) {
    if(ptr->data == key) {
      searches_suc++;
      break;
    }
    else
      ptr = ptr->next;
  }
}

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");

  //Initialize Table
  for(int i = 0; i < BUCKETS; i++)
    table[i] = NULL;

  // Read commands and execute
  char cmd;
  int key;
  int flag;
  while(1) {
    flag = fscanf(f,"%c\t%d\n", &cmd, &key);
    if(flag == EOF)
      break;
    if(cmd == 'i')
      insert(key);
    else if (cmd == 's')
      search(key);
  }
  fclose(f);

  printf("%d\n%d", collisions, searches_suc);

  return 0; // Exit sucessfully
}
