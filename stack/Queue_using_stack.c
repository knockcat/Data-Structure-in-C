//Implement Queue using Stack (lIFO) TO (FIFO)

#include<stdio.h>
#include<stdlib.h>
#define Max 5
int stack1[Max], stack2[Max];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int);
void push2(int);

void enqueue(int x)
{
	push1(x);
	count++;
}

void dequeue()
{
	int i;
	int a,b;
	if(top1 == -1 && top2 == -1)
		printf("\nQueue is Empty\n");
	else
		for(i = 0; i < count; i++)
		{
			a = pop1();
			push2(a);
		}
	    b = pop2();
		printf("The dequed element is %d",b);
		
		count--;
		for(i = 0; i < count; i++)
		{
			a = pop2();
			push1(a); 
		}
}

void push1(int data)
{
	if(top1 == Max-1)
	{
		printf("\nQueue is Full\n");
	}
	else
	{
		top1++;
		stack1[top1] = data;
	}
}

void push2(int data)
{
	if(top2 == Max-1)
	{
		printf("\nQueue is Full\n");
	}
	else
	{
		top2++;
		stack2[top2] = data;
	}
}

int pop1()
{
	return stack1[top1--];
}

int pop2()
{
	return stack2[top2--];
}

void display()
{
	int i;
	for(i = 0; i <= top1; i++)
	{
		printf("%d ",stack1[i]);
	}
}

int main()
{
	int choice;
	
	
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			int data;
			case 1:
				printf("Enter data : ");
				scanf("%d",&data);
				enqueue(data);
				break;
			case 2:
				dequeue(data);
				break;
			case 3:
				display(data);
				break;
			case 4:
				exit(0);
				break;
		}
	}

	return 0;
}
