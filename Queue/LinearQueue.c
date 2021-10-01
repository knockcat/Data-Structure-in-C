//Linear Queue
#include <stdio.h>
#include <stdlib.h>
#define Max 5
int rear = -1;
int front = -1;
int queue[Max];

void Enqueue(int data)
{
	if (rear == Max - 1)
	{
		printf("Queue is Full");
		return;
	}
	if (front == -1)
		front = 0;

	rear++;
	queue[rear] = data;
}

int Dequeue()
{
	int item;
	if (front == -1 || front == rear + 1)
	{
		printf("Queue is Empty");
		exit(1);
	}
	else
	{
		item = queue[0];
		front = front + 1;
		return item;
	}
}

void peek()
{
	printf("Top Element is %d ", queue[front]);
}

void display()
{
	for (int i = front; i <= rear; i++)
	{
		printf("\ndata %d at index %d\n", queue[i], i);
	}
}

int main()
{
	int data;
	int choice, del;
	while (1)
	{
		printf("\n1. Enque : ");
		printf("\n2. Dequeue : ");
		printf("\n3. peek : ");
		printf("\n4. Display : ");
		printf("\n5. Exit ");

		printf("\nEnter Your Choice ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter Data : ");
			scanf("%d", &data);
			Enqueue(data);
			break;

		case 2:

			del = Dequeue();
			printf("\nDeleted data is  %d ", del);
			break;

		case 3:
			peek();
			break;

		case 4:
			display();
			break;

		case 5:
			exit(1);
			break;
		}
	}
	return 0;
}
