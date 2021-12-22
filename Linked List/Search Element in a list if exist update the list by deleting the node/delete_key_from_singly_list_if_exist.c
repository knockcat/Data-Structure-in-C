//frame a singly linked list, then take a key from user if that key exist update the list by deleting that key otherwise print key not found...

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
	newp->next = NULL;

	return newp;
}

struct node *addtoend(struct node *ptr, int data)
{
	struct node *temp = ptr;
	struct node *newp = (struct node *)malloc(sizeof(struct node));
	newp->data = data;
	newp->next = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newp;

	return ptr;
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
		return NULL;

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

struct node *del_key(struct node *head, int key)
{
	struct node *prev = head;
	struct node *curr = head;
	int flag = 0;

	if (head == NULL)
	{
		printf("List is already empty");
	}
	else if (head->data == key)
	{
		flag = 1;
		head = head->next;
		free(curr);
		curr = NULL;
	}
	else
	{
		while (curr != NULL && curr->next != NULL)
		{
			curr = curr->next;
			if (curr->data == key)
			{
				flag = 1;
				prev->next = curr->next;
				free(curr);
				curr = NULL;
			}
			prev = prev->next;
		}
	}

	if (flag == 0)
		printf("\nkey Not found!!!\n");
	else
		printf("\nKey Found and deleted\n");

	return head;
}

int main()
{
	struct node *head;
	int key;
	head = createlist(head);
	print(head);

	printf("\n\nEnter the key you want to delete: ");
	scanf("%d", &key);

	head = del_key(head, key);

	print(head);
	return 0;
}
