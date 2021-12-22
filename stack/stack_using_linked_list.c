//stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int menu()
{
	int choice;
	printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
	printf("\nEnter your choice : " );
	scanf("%d",&choice);
	return choice;
}

struct node *push(struct node *ptr)
{
    int data;
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp ==  NULL)
        printf("\nMemory not available\n");
    else
    {
        printf("\nEnter Data : ");
        scanf("%d",&data);

        if(ptr == NULL)
        {
            temp -> data = data;
            temp -> next = NULL;
        }
        else
        {
            temp ->data = data;
            temp -> next = ptr;
            
        }

        ptr = temp;
    }

    return ptr;
}

struct node *pop(struct node *ptr)
{
    if(ptr == NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        struct node *temp = ptr;
        printf("\npopped element is : %d\n",temp->data);
        
        ptr = ptr -> next;
        free(temp);
        temp =  NULL;
    }

    return ptr;
}

void peek(struct node *ptr)
{
    if(ptr == NULL)
        printf("\nStack is Empty\n");
    else    
        printf("\nStack top is : %d\n",ptr -> data);
}

void display(struct node *ptr)
{
    if(ptr == NULL)
        printf("\nstack is EMpty \n");
    else
    {
        while(ptr != NULL)
        {
            printf("\ndata : %d\n",ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main()
{
	struct node *top = NULL;
    struct node *ptr = top;
    int choice;
	
	
	while(1)
	{
		choice = menu();
		
		switch(choice)
		{
			case 1:
				ptr = push(ptr);
				break;
			case 2:
				ptr = pop(ptr);
				break;
			case 3:
				peek(ptr);
				break;
			case 4:
				display(ptr);
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
