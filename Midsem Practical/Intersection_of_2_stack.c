//Intersection of 2 Stack

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *data;
} stack;

stack *create(int size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->capacity = size;
    s->data = (int *)malloc(sizeof(int) * size);
    return s;
}
void push(stack *s)
{
    int num;
    printf("Enter the Element to push\n");
    scanf("%d", &num);
    if (s->top == s->capacity - 1)
    {
        printf("Stack is Full...!!\n");
        return;
    }
    s->top++;
    printf("%d ", s->top);
    s->data[s->top] = num;
}
void pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty...!!\n");
        return;
    }
    s->top--;
}
void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Empty Stack..!!\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
void peek(stack *s)
{
    if (s->top == -1)
    {
        printf("Empty Stack..!!\n");
        return;
    }
    printf("%d \n", s->data[s->top]);
}
void sort(stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        for (int j = i; j <= s->top; j++)
        {
            if (i != j)
            {
                if (s->data[i] < s->data[j])
                {
                    int temp = s->data[i];
                    s->data[i] = s->data[j];
                    s->data[j] = temp;
                }
            }
        }
    }
}
int main()
{
    int n1, n2;
    printf("Enter the Size of first stack\n");
    scanf("%d", &n1);
    printf("Enter the Size of second stack\n");
    scanf("%d", &n2);
    stack *s1 = create(n1);
    stack *s2 = create(n2);
    printf("Operation for 1st stack\n");
    while (1)
    {
        printf("choice are ..\n1:-push \n 2- pop \n 3-display \n 4 - peek \n 5- exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 5)
            break;
        switch (choice)
        {
        case 1:
            push(s1);
            break;
        case 2:
            pop(s1);
            break;
        case 3:
            display(s1);
            break;
        case 4:
            peek(s1);
        default:
            break;
        }
    }
    printf("Operation for 2nd stack\n");
    while (1)
    {
        printf("choice are ..\n1 -Push \n 2- Pop \n 3 - Display \n 4 - Peek \n 5- Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 5)
            break;
        switch (choice)
        {
        case 1:
            push(s2);
            break;
        case 2:
            pop(s2);
            break;
        case 3:
            display(s2);
            break;
        case 4:
            peek(s2);
        default:
            break;
        }
    }
    sort(s1);
    sort(s2);
    while (s1->top != -1 && s2->top != -1)
    {
        if (s1->data[s1->top] == s2->data[s2->top])
        {
            printf("%d ", s1->data[s1->top]);
            pop(s1);
            pop(s2);
        }
        else if (s1->data[s1->top] > s2->data[s2->top])
        {
            pop(s2);
        }
        else
            pop(s1);
    }
}
