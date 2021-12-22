//frame a doubly linked list, then take a key from user if that key exist update the list by deleting that key otherwise print key not found...

#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev, *next;
	int data;
};

struct node *addtoempty(int data)
{
	struct node *newp = (struct node *)malloc(sizeof(struct node));
	newp->prev = NULL;
	newp->data = data;
	newp->next = NULL;

	return newp;
}

struct node *addtoend(struct node *ptr, int data)
{
	struct node *temp = ptr;
	struct node *newp = (struct node *)malloc(sizeof(struct node));
	newp->prev = NULL;
	newp->data = data;
	newp->next = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	newp->prev = temp;
	temp->next = newp;

	return ptr;
}

struct node *del_key(struct node *head, int key)
{
	struct node *pr = NULL;
	struct node *curr = head;
	int flag = 0;

	if (head == NULL) //if list is empty
	{
		printf("List is already empty");
	}
	else if (head->data == key) //if node happened to be the first node
	{
		flag = 1;
		head = head->next;
		head->next->prev = NULL;
		free(curr);
		curr = NULL;
	}
	else
	{
		while (curr != NULL && curr->next != NULL)
		{
			if (curr->data == key)
			{
				flag = 1;
				pr = curr->prev; //giving pr the refernce of prev pointer to current
				pr->next = curr->next;

				curr->next->prev = pr;
				free(curr);
				curr = NULL;
				return head; // returnig head as nodes has been updated
			}
			curr = curr->next;
		}

		if (curr->data == key) // if deleted node happen to be last node
		{
			flag = 1;
			pr = curr->prev;
			pr->next = curr->next;
			free(curr);
			curr = NULL;
		}
	}

	if (flag == 0)
		printf("\nkey Not found!!!\n");
	else
		printf("\nKey Found and deleted\n");

	return head;
}

void print(struct node *ptr)
{
	if (ptr == NULL)
		printf("No node in the list ");
	while (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
}

struct node *createlist(struct node *ptr)
{
	int i, n, data;
	printf("Enter the number of nodes of the linked list : ");
	scanf("%d", &n);

	if (n == 0)
		return ptr;

	printf("Enter the element 1 : ");
	scanf("%d", &data);
	ptr = addtoempty(data);

	for (i = 1; i < n; i++)
	{
		printf("Enter the element %d : ", i + 1);
		scanf("%d", &data);
		ptr = addtoend(ptr, data);
	}
	return ptr;
}

int main()
{
	struct node *head = NULL;
	struct node *ptr;
	int key;
	head = createlist(head);

	print(head);

	printf("\n\nEnter the key you want to delete: ");
	scanf("%d", &key);

	head = del_key(head, key);

	print(head);
}
