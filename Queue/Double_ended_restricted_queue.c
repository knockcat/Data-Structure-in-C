//double ended restricted queue (priority queue)

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
	int data;
    int c,n;
    do{
        printf("\n0:exit\n1:input restricted\n2:output restricted\nenter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 0:c=0;
            break;
            case 1:
            do
            {
                printf("\n0:exit\n1:add\n2:delete from front\n3:delete from rear\n4:get front\n5:get rear\n6:Display\nenter your choice:");
                scanf("%d",&n);
                switch(n)
                {
                    case 0:n=0;
                    break;
                    case 1:
                    printf("Enter Data : ");
                    scanf("%d",&data);
					enqueuerear(data);
                    break;
                    
                    case 2:dequeuefront();
                    break;
                    
                    case 3:dequeuerear();
                    break;
                    
                    case 4:getfront();
                    break;
                    
                    case 5:getrear();
                    break;
                    
                    case 6:display();
                    break;
                    
                    default:printf("\ninvalid choice");
                    break;
                }
            }while(n);
            break;
            case 2:
            do
            {
                printf("\n0:exit\n1:delete\n2:add from front\n3:add from rear\n4:get front\n5:get rear\n6:Display\nenter your choice:");
                scanf("%d",&n);
                switch(n)
                {
                    case 0:n=0;
                    break;
                    case 1:
					dequeuefront();
                    break;
                    
                    case 2:
                	printf("Enter Data : ");
                	scanf("%d",&data);
					enqueuefront(data);
                    break;
                    
                    case 3:
                    printf("Enter Data : ");
                	scanf("%d",&data);
					enqueuerear(data);
                    break;
                    
                    case 4:getfront();
                    break;
                    
                    case 5:getrear();
                    break;
                    
                    case 6:display();
                    break;
                    
                    default:printf("\ninvalid choice");
                    break;
                }
            }while(n);
        }
    }while(c);
    return 0;
}
