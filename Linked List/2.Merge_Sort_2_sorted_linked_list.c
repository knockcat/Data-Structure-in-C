// Merge and sort two sorted Linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

//Insertion in the list

void insert(struct node **head, int data)
{
    struct node *ptr = *head;
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr->next->data = data;
    ptr->next->next = NULL;
    return;
}

//Display Function

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

//Sort FUnction

void sortll(struct node **head)
{
    if (*head == NULL)
        return;
    sortll(&((*head)->next));
    struct node *temp = *head, *headreturn = *head;
    while (temp->next != NULL && (*head)->data > temp->next->data)
    {
        temp = temp->next;
        headreturn = (*head)->next;

        if (temp->next == NULL || (*head)->data <= temp->next->data)
        {
            (*head)->next = temp->next;
            temp->next = *head;
            break;
        }
    }
    *head = headreturn;
}

//Merging two list

void mergell(struct node *head1, struct node *head2)
{
    struct node *ptr = head1;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head2;
    return;
}
int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int l = 1;
    while (l)
    {
        printf("Enter 1st ll : ");
        printf("1.Insert   2.Exit \n");
        int choice, value, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &data);
            insert(&head1, data);
            break;
        case 2:
            l = 0;
            break;
        }
    }
    sortll(&head1); //sorting list 1

    printf("\n\nList 1\n\n");
    display(head1);
    l = 1;
    while (l)
    {
        printf("Enter 2nd ll : ");
        printf("1.Insert   2.Exit \n");
        int choice, value, data;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &data);
            insert(&head2, data);
            break;
        case 2:
            l = 0;
            break;
        }
    }
    sortll(&head2);      //sorting list 2

    printf("\n\nList 2\n\n");
    display(head2);

    mergell(head1, head2);  //calling Merge function

    sortll(&head1);     //sort the merge list 

    display(head1);     //display sorted merged list
    return 0;
}