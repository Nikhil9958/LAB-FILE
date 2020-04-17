/* C program for creating ,deleting and displaying the contents of a doubly link list */
#include<stdio.h>
#include<stdlib.h>
struct node // creating the structure of node
{
    struct node*prev,*next;
    int data;
}*first=NULL;
void create(int n) // create function for creating  a link list
{
    int data;
    struct node*temp,*last;
    printf("PLEASE ENTER THE DATA:");
    scanf("%d",&data);
    first=(struct node*)malloc(sizeof(struct node));
    first->data=data;
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        printf("PlEASE ENTER THE DATA:");
        int d;
        scanf("%d",&d);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->next=NULL;
        temp->prev=last;
        last->next=temp;
        last=temp;
    }
}
void traverse() // function for traversing a link list
{
    struct node*temp=first;
    int i=1;
    while(temp)
    {
        printf("\nPrinting the %d element and its value = %d",i,temp->data);
        i++;
        temp=temp->next;
    }

}
void delete() // function for deleting a link list
{
    int pos;
    struct node*p=NULL,*q=first;
    printf("\nPlease enter the position:");
    scanf("%d",&pos);
    int x;
    if(pos==1)
    {
        x=first->data;
        first=first->next;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=q;
            q=q->next;
        }
        x=q->data;
        p->next=q->next;
        q->next->prev=p;
        free(q);
    }
    printf("\nThe element with position %d is deleted with value having %d",pos,x);
}
void main() // main function
{
    int n;
    printf("Please enter the no. of nodes:");
    scanf("%d",&n);
    create(n);
    traverse();
    delete();
    traverse();
}

