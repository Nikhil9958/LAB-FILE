/*Program to create a binary search tree of characters and traverse in preorder,postorder,inorder*/
#include <stdio.h>
#include<stdlib.h>

//Creating structure of node
typedef struct node
    {

        char data;
        struct node *left;
        struct node *right;

    }Node;
struct node *CreateTree()  //create function for creating tree
{
    char Nodedata;
    Node *newnode=(Node*)malloc(sizeof(Node)); //dynamic memory allocation
    printf("Enter the data for the nodes(0 for no data)");
    fflush(stdin);
    scanf("%c",&Nodedata);
    if(Nodedata=='0')
    {
        return NULL;
    }
    newnode->data=Nodedata;
    printf("Enter the left child data rooted at %c \n",newnode->data);
    newnode->left=CreateTree();
    printf("Enter the right child data rooted at %c\n",newnode->data);
    newnode->right=CreateTree();
    return newnode;
}
void traverse(Node *t)
{
    if(t!=NULL)
    {
        printf("Left child data is %c ",t->data);
        traverse(t->left);
        t=t->right;
    }
    if(t!=NULL)
    {
       printf("Right child data is %c\n",t->data);
       traverse(t->right);
    }
}
void Inorder(Node *t)
{
    if(t)
    {
        Inorder(t->left);
        printf("%c ",t->data);
        Inorder(t->right);
    }
}
void Preorder(Node *t)
{
    if(t)
    {
        printf("%c ",t->data);
        Preorder(t->left);
        Preorder(t->right);
    }
}
void Postorder(Node *t)
{
    if(t)
    {
        Postorder(t->left);
        Postorder(t->right);
        printf("%c ",t->data);
    }
}
void Double(Node *t)
{
    if(t)
    {
        printf("%c ",t->data);
        Double(t->left);
        printf("%c ",t->data);
        Double(t->right);
    }
}
int main()
{
    Node *root=CreateTree(); //final return root from function CreateTree
    Node *t=root;   //assign root node to another node t
    printf("\nRoot of the Binary Tree is %c\n ",t->data);
    printf("\n\nPreoder traversing is\n");
    Preorder(t);
    printf("\n\nInorder traversing is\n");
    Inorder(t);
    printf("\n\nPostorder traversing is\n");
    Postorder(t);
    printf("\n\nDoubleorder traversing is\n");
    Double(t);
    return 1;
}
