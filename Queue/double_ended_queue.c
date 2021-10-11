/*
dequeue  (double ended queue)
Insertion and deletion from both the end
*/

//(stack lifo) (queue fifo)

/*
Types of Dequeue 
input restricted  ->	insertion can only be from one end only.deletion is possible from both end.
output restricted ->	deletion can only be from one end only. insertion is possible from both the end.
*/
/*
Operations
insert at front
delete from front
insert from rear
delete from rear

get front
get rear

isfull()
isempty()
*/

/*
Implementation can be done through circular array or doubly linked list

all operation take O(1) time complexity

dequeue is used in multiprocessor scheduling (A - steal Algorithm)
*/

#include<stdio.h>
#define Max 5
#include<stdlib.h>
int dequeue[Max];
int f = -1;
int r = -1;

void enqueuefront(int x)
{
	if((f == 0 && r == Max - 1) || (f == r + 1))
		printf("\nQueue is Full\n");
	else if(f == -1 && r == -1)
	{
		f = r = 0;
		dequeue[f] = x;	
	}
	else if(f == 0)
	{
		f = Max - 1;
		dequeue[f] = x;
	}
	else
	{
		f--;			//for inserting from front we will do front--
		dequeue[f] = x;
	}
}

void enqueuerear(int x)
{
	if((f == 0 && r == Max - 1) || (f == r + 1))
		printf("\nQueue is Full\n");
	else if(f == -1 && r == -1)
	{
		f = r = 0;
		dequeue[r] = x;
	}
	else if(r == Max -1)
	{
		r = 0;
		dequeue[r] = x;
	}
	else
	{
		r++;			//for inserting from rear we will do rear++ ( normal queue condition) 
		dequeue[r] = x;
	}
	
}

void display()
{
	int i = f;
	if(f == -1 && r == -1)
		printf("\nQueue is Empty\n");
	while(i != r)
	{
		printf("%d ",dequeue[i]);
		i = (i+1) % Max;
	} 
	printf("%d",dequeue[r]);
	
}

void getfront()
{
	printf("%d",dequeue[f]);
}

void getrear()
{
	printf("%d",dequeue[r]);
}

void dequeuefront()
{
	if(f == -1 && r == -1)
		printf("\nQueue is Empty\n");
	else if(f == r)
	{	
		printf("The dequeued element is %d",dequeue[f]);
		f = r = -1;
	}
	else if(f == Max - 1)
	{
		printf("The dequeued element is %d",dequeue[f]);
		f = 0;	
	}
	
	else
	{
		printf("The dequeued element is %d",dequeue[f]);
		f++;
	}
}

void dequeuerear()
{
	if(f == -1 && r == -1)
		printf("\nQueue is Empty\n");
	else if(f == r)
	{	
		printf("The dequeued element is %d",dequeue[r]);
		f = r = -1;
	}
	else if(r == 0)
	{
		printf("The dequeued element is %d",dequeue[r]);
		r = Max - 1;
	}
	else
	{
		printf("The dequeued element is %d",dequeue[r]);
		r--;
	}
	
}

int main()
{
	int choice;
	
	
	while(1)
	{
		printf("\n1.Enqueue From Front\n2.Enqueue From Rear\n3.Dequeue From Front\n4.Dequeue From Rear\n5.Display\n6.Get Front\n7.Get Rear\n8.Exit\n");
		scanf("%d",&choice);
		system("cls");
		switch(choice)
		{
			int data;
			case 1:
				printf("Enter data : ");
				scanf("%d",&data);
				enqueuefront(data);
				break;
			case 2:
				printf("Enter data : %d",&data);
				enqueuerear(data);
				break;
			case 3:
				dequeuefront();
				break;
			case 4:
				dequeuerear();
				break;
			case 5:
				display();
				break;
			case 6:
				getfront();
				break;
			case 7:
				getrear();
				break;	
			case 8:
				exit(0);
				break;
		}
	}

	return 0;
}
 
