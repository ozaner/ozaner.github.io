#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node* root = NULL;

node* createNode(int data) {
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

node* insert(node* node, int data) {
    if (node == NULL)
      return createNode(data);

    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

void inorder(node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main(int argc, char **argv) {
  FILE *f = fopen(argv[1], "r");

  // Read and perform inserts
  int num;
  int flag;
  while(1) {
    flag = fscanf(f,"i\t%d\n", &num);
    if(flag == EOF)
      break;
    root = insert(root, num);
  }
  fclose(f);

  inorder(root);

  return 0; // Exit sucessfully
}
