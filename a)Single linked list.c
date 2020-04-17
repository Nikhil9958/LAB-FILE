/* C program for creating ,deleting and displaying the contents of a link list */
#include<stdio.h>
#include<stdlib.h>
struct node//creating the structure of node
{
    int data;
    struct node*next;
}*head=NULL;
void create(int n) // create function for creating a node
{
    int data;
    struct node*temp;
    head=(struct node*)malloc(sizeof(struct node)); //dynamic memory allocation
    if(head==NULL)
    {
        printf("Memory not allocated");
        return;
    }
    printf("Enter first node data");
    scanf("%d",&data);
    temp=head;
    head->data=data;
    head->next=NULL;
    for(int i=2;i<=n;i++)
    {
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory not allocated");
            break;
        }
        printf("Enter Node data");
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    printf("List created successfully!\n");

}
void traverselist() //function for traversing a list
{
    struct node*temp=head;
    int i=1;
    while(temp)
    {
        printf("Printing %d element of linked list %d\n",i,temp->data);
        i++;
        temp=temp->next;
    }
}
void delete(int pos) //function for deleting any element in the link list
{
    struct node*p=NULL,*q=head;

    int x=0;
    if(pos==1)
    {
        head=head->next;
        x=q->data;
    }
    else{


    for(int i=0;i<pos-1 &&q;i++)
    {
        p=q;
        q=q->next;
    }
    if(q){
    p->next=q->next;
    x=q->data;
    }
    }
    printf("\nThe position number %d is deleted with data having %d \n",pos,x);

}
int main() // defining the main function
{
    int n;
    printf("Please Enter the number of nodes");
    scanf("%d",&n);
    create(n);
    traverselist();
    int pos;
    printf("\nPlease enter the position:");
    scanf("%d",&pos);
    delete(pos);
    traverselist();
}
