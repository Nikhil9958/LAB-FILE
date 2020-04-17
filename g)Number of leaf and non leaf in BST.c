//Number of Leaf and non Leaf nodes in a Binary Tree
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;
void Insert(int key)
{
	struct Node *t=root;    //t and r are temporary variable
	struct Node *r=NULL,*new_node;
	if(root==NULL)    //create a root node
	{
		new_node=(struct Node *)malloc(sizeof(struct Node));
		new_node->data=key;
		new_node->lchild=new_node->rchild=NULL;
		root=new_node;
		return;
	}
	while(t!=NULL)   //It is use for where insert a new_node
	{
		r=t;
		if(key<t->data)
			t=t->lchild;
		else
		if(key>t->data)
			t=t->rchild;
		 else
		 	return;
    }
    new_node=(struct Node *)malloc(sizeof(struct Node));    //create a binary tree
    new_node->data=key;
    new_node->lchild=new_node->rchild=NULL;
    if(key<r->data)
    	r->lchild=new_node;
    else
    	r->rchild=new_node;
}
int noofleafNodes(struct Node *root)
{
	if (root==NULL)
	{
        return 0;
	}
	else
		if (root->lchild==NULL && root->rchild==NULL)
		{
			return 1;
		}
		else
			return(noofleafNodes(root->lchild)+noofleafNodes(root->rchild));
}
int nononleafNodes(struct Node *root)
{

	if( (root==NULL) || ((root->lchild==NULL) && (root->rchild==NULL)))
	  return 0;
	else
	 return (nononleafNodes(root->lchild)   + nononleafNodes(root->rchild) + 1);
}
int main()
{
	int num,n;
	printf("Enter the number of elements to be inserted in Binary tree:\n");
	scanf("%d",&n);
	printf("Enter the elements :\n");
	for (int i = 0; i < n;i++)
	{
		scanf("%d",&num);
		Insert(num);
	}
    printf("Number of leaf nodes is :%d\n",noofleafNodes(root));
    printf("\nNumber of non leaf nodes is:%d\n",nononleafNodes(root));
    return 0;
}
