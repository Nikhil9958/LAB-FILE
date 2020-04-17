/*program that uses stack operations to convert a given infix expression into its postfix Equivalent, Implement the stack using an array*/
#include<stdio.h>
char stack[20];
int top = -1;
void push(char x) // defining the push function
{
    stack[++top] = x;
}

char pop() // defining the pop function
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) // priority function for checking the priority of elements
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main() // main function
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
