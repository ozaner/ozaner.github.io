#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct node {
  int data;
  struct node *next;
} node;

// Global Variables
node* head = NULL;

node* createNode(int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert(int num) {
  node* newNode = createNode(num);
  if (head == NULL)
    head = newNode;
  else if (head->data >= num) {
    newNode->next = head;
    head = newNode;
  }
  else {
    node* ptr = head;
    int index = 0;
    while (ptr != NULL) {
      if(ptr->data >= num)
        break;
      ptr = ptr->next;
      index++;
    }
    index--;
    ptr = head;
    for(int i = 0; i < index; i++)
      ptr = ptr->next;
    newNode->next = ptr->next;
    ptr->next = newNode;
  }
}

void delete(int num) {
  if (head == NULL)
    return;
  else if (head->data == num)
    head = head->next;
  else {
    node* ptr = head;
    int index = 0;
    while (ptr != NULL) {
      if(ptr->data == num)
        break;
      ptr = ptr->next;
      index++;
    }
    index--;
    ptr = head;
    for(int i = 0; i < index; i++)
      ptr = ptr->next;
    if(ptr == NULL)
      return;
    else
      if(ptr->next != NULL)
        ptr->next = ptr->next->next;
  }
}

int getElement(int index) {
  node *ptr = head;
  for(int i = 0; i < index; i++) {
    ptr = ptr->next;
  }
  return ptr->data;
}

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");
  if(!f) {
    printf("error");
    return 0;
  }
  // Read commands and execute
  char cmd;
  int num;
  int flag;
  while(1) {
    flag = fscanf(f,"%c\t%d\n", &cmd, &num);
    if(flag == EOF)
      break;
    if(cmd == 'i')
      insert(num);
    else if (cmd == 'd')
      delete(num);
  }
  fclose(f);

  //Print Output
  if(head == NULL)
    printf("0\n");
  else {
    //Total Count
    int total = 0;
    node *ptr = head;
    while(ptr != NULL) {
      ptr = ptr->next;
      total++;
    }
    printf("%d\n",total);

    //Unique Elements
    int last = head->data;
    printf("%d",last);
    ptr = head;
    while(ptr != NULL) {
      if(ptr->data != last) {
        last = ptr->data;
        printf("\t%d",last);
      }
      ptr = ptr->next;
    }
  }

  return 0; // Exit sucessfully
}
