#include<stdio.h>
#include<stdlib.h>
#define MAX 5



int sarr[MAX];
int top = -1;

int isfull()
{
    if(top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return  0;
}

void push( int data)
{
    if(isfull())
    {
        printf("Stack is Overflow");
    }
    else
    {
        top += 1;
        sarr[top] = data;
    }
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack is Underflow");
    }
    else
    {
        int value = sarr[top];
        top -= 1;
        return value;
    }
}

void peek()
{
    printf("\nTop Most Element of Stack is : %d",sarr[top]);
}

void display()
{
    for(int i = top ; i>=0; i--)
        printf("\nData %d at Index %d\n",sarr[i],i);
}



int main()
{
    int opt,data,item;
    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&opt);

        switch(opt)
        {
            
            case 1:
            printf("\nEnter Data : ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            item = pop();
            printf("\nPopped Element is : %d",item);
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(1);

            default:
            printf("\nInvalid Option");
            break;
        }
    }
    
}