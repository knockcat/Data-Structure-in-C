// Program to implement a Queue using Linked list without using user defined data type

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void **Enqueue(void **temp)
{
    temp[1] = (void *)calloc(2, sizeof(void *));
    temp = temp[1];

    temp[0] = (int *)malloc(sizeof(int));
    temp[1] = NULL;
    printf("\nenter an int element: ");
    scanf("%d", (int *)temp[0]);
    return temp;
}

void **Dequeue(void **head)
{
    void **temp1 = NULL;
    if (head == NULL)
        printf("---Queue is Empty ---\n");
    else
    {
        temp1 = head[1];
        free(head);
        head = temp1;
    }
    return head;
}

void Display(void **head)
{
    if (head == NULL)
    {
        printf("---Queue is Empty ---\n");
        return;
    }
    void **temp;
    for (temp = head; temp != NULL; temp = temp[1])
        printf("%d\n", *((int *)(temp[0])));
    return;
}

void Front(void **temp)
{
    if (temp == NULL)
        printf("---Queue is Empty ---\n");
    else
        printf(" 1st element of Queue is %d\n", *((int *)(temp[0])));
    return;
}

int main()
{
    void **head = NULL, **temp = NULL;
    while (1)
    {
        printf("Enter your Choice : 1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit \n");
        int choice, value;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (head == NULL)
            {
                temp = head = (void *)calloc(2, sizeof(void *));
                temp[0] = (int *)malloc(sizeof(int));
                temp[1] = NULL;
                printf("\nenter an int element: ");
                scanf("%d", (int *)temp[0]);
            }
            else
                temp = Enqueue(temp);
            break;

        case 2:
            head = Dequeue(head);
            break;

        case 3:
            Front(head);
            break;

        case 4:
            Display(head);
            break;

        case 5:
            return 0;
        }
    }
    return 0;
}