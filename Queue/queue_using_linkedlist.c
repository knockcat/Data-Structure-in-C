//Queue using Linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int menu()
{
	int choice;
	printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
	printf("Enter your choice : " );
	scanf("%d",&choice);
	return choice;
}

struct node *enqueue(struct node *rear)
{
    struct node *ptr;
    int data;
    ptr = (struct node *)malloc(sizeof(int));

    if(ptr ==  NULL)
        printf("\nMemory Not Availble\n");
    else
    {
        printf("\nEnter Data \n");
        scanf("%d",&data);
        ptr->data = data;
        ptr ->next = NULL;
        
        if(rear == NULL)
        {
            rear = ptr;
        }

        else
        {
            rear -> next = ptr;
            rear = ptr;
            
        }
        
    }
    return rear;
}

struct node *dequeue(struct node *front)
{
    if(front == NULL)
        printf("\nQueue is Empty");
    else
    {
        printf("\nDeleted Element is %d",front->data);

        if(front ->next == NULL)
        {
            front = NULL;
        }
        else
        {
            if(front->next == NULL)
                front = NULL;
            else{
             struct node * ptr = front;
             front = front -> next;
             free(ptr);
             ptr = NULL;
            }
        }

    }
    return front;
}

void display(struct node *front)
{
    if(front == NULL)
        printf("\nQueue is Empty\n");
    else
    {
        while(front != NULL)
        {
            printf("\nData : %d",front ->  data);
            front = front -> next;
        }
    }
}
void peek(struct node *front)
{
    if(front ==  NULL)
        printf("\nQueue is Empty\n");
    else
        printf("\nPeek element is %d\n",front->data);
}

int main()
{
    struct node *rear = NULL;
    struct node *front = NULL;
    int choice;
    while(1)
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
				rear = enqueue(rear);
                if(front == NULL)
                    front = rear;
				break;
			case 2:
                front = dequeue(front);
				
				break;
			case 3:
				peek(front);
				break;
			case 4:
				display(front);
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("\nInvalid Option\n");
				break;
		}
	}
}
