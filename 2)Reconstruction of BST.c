// *********************Author is NIkhil Kumar Arora,IT branch,IIIT Sonepat********************
//This program contains the reconstruction and the rotation method used to reconstruct a BST to AVL
#include<stdio.h>
#include<stdlib.h>

struct Node//stucture of node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);

int height(struct Node *N) //function for height of node
{
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b)
{
  return (a > b)? a : b;
}

struct Node* newNode(int key)//creating new node
{
  struct Node* node = (struct Node*)
            malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return(node);
}

struct Node *rightRotate(struct Node *y)//right roatate function
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  return x;
}

struct Node *leftRotate(struct Node *x)//left rotate function
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;

  return y;
}

int getBalanceFactor(struct Node *N)//balance factor function
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct Node* insertNode(struct Node* node, int key)// insert in tree
{
  if (node == NULL)
    return(newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left),
            height(node->right));
     printf("\n Height of new tree(assume leaf node height is 1):%d",((node->height)-1));


  int balanceFactor = getBalanceFactor(node);


  if (balanceFactor > 1)
  {
    if (key < node->left->key)
    {
      return rightRotate(node);

    }
    else if (key > node->left->key)
    {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1)
  {
    if (key > node->right->key)
    {
      return leftRotate(node);
    }
    else if (key < node->right->key)
    {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

struct Node * minValueNode(struct Node* node)
{
  struct Node* current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

void printPreOrder(struct Node *root)
{
  if(root != NULL)
  {
    printf("\n");
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

int main()
{
struct Node *root = NULL;
  printf("\n Method used is: RR");
  root = insertNode(root, 1);
  root = insertNode(root, 2);
  root = insertNode(root, 3);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 6);

  printPreOrder(root);




}
