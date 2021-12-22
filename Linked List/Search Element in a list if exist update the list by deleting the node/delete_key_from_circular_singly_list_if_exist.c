//frame a circular singly linked list, then take a key from user if that key exist update the list by deleting that key otherwise print key not found...

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *addtoempty(int data)
{
    struct node *newp = (struct node *)malloc(sizeof(struct node));
    newp->data = data;
    newp->next = newp;

    return newp;
}

struct node *addtoend(struct node *tail, int data)
{
    struct node *newp = (struct node *)malloc(sizeof(struct node));
    newp->data = data;
    newp->next = tail->next;
    tail->next = newp;

    tail = tail->next;

    return tail;
}

struct node *createlist(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes of the linked list : ");
    scanf("%d", &n);

    if (n == 0)
        return NULL;

    printf("Enter the element 1 : ");
    scanf("%d", &data);
    tail = addtoempty(data);

    for (i = 1; i < n; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &data);
        tail = addtoend(tail, data);
    }
    return tail;
}

struct node *del_key(struct node *head, int key)
{
    int flag = 0;
    struct node *temp = head;
    struct node *temp2, *temp3;
    if (temp == NULL)
    {
        printf("\nLinked List is Empty\n");
        exit(0);
    }
    if (temp->next == temp && temp->data == key)
    { //Checking if we have single Node and that contain keyvalue
        printf("\nLinked list contain single node and that one is also deleted\n");
        free(temp);
        head = NULL;
        return head;
    }
    else if (temp->data == key) //first node of linked list contain keyvalue
    {
        printf("\nElement Found and node is deleted\n");
        temp3 = temp;
        while (temp3->next != head)
        {
            temp3 = temp3->next;
        }
        temp3->next = temp->next;
        temp2 = temp;
        head = head->next;
        free(temp2);
        return head;
    }
    else
    { //traversing whole linked list to search and delete
        while (temp->next != head)
        {
            if (temp->data == key)
            {
                flag = 1;
                break;
            }
            temp2 = temp;
            temp = temp->next;
        }
        if (temp->data == key)
            flag = 1;
        if (flag == 1)
        {
            printf("Element Found and node is deleted\n");
            temp2->next = temp->next;
            free(temp);
        }
        else
            printf("Element not found!!");
    }
    return head;
}

void print(struct node *tail)
{
    if (tail == NULL)
        printf("No node in the list ");

    else
    {
        struct node *newp = tail->next;

        do
        {
            printf("%d\t", newp->data);
            newp = newp->next;
        } while (newp != tail);
        printf("%d\t", newp->data);
    }
}

int main()
{
    struct node *tail;
    int key;
    tail = createlist(tail);
    print(tail);

    printf("\n\nEnter the key you want to delete: ");
    scanf("%d", &key);

    tail = del_key(tail, key);

    print(tail);
    return 0;
}
