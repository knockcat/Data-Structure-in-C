#include<stdio.h>
#include<stdlib.h>

int *push(int *p, int *top)
{
	int *ptr = NULL;
	if(p == NULL)
		ptr = (int *) calloc(1,sizeof(int));
	else
		ptr = (int *)realloc(p,sizeof(int)*((*top)+1));
	if(ptr == NULL)
		printf("No more memory is available");
	else
	{
		(*top)+= 1;
		p = ptr;
		printf("Enter data :");
		scanf("%d",&p[(*top)]);
	}
	return p;
}
	
int *pop(int *p, int *top)
{
	int *ptr = NULL;
	if(p == NULL)
		printf("\n Stack is Empty \n");
	else
	{
		printf("\n curren top %d\n",p[(*top)]);
		
		(*top)-= 1;
		
		printf("\nnew top %d\n",p[(*top)]);
		if((*top)!= -1)
			ptr = (int*)realloc(ptr,sizeof(int)*(*top));
		//p = ptr;
		ptr = p;
		
	}
	//return p;
	return ptr;
}
		
void peek(int *p, int top)
{
	if(p == NULL)
		printf("Stack is Empty");
	else
		printf("The top most element is %d ",p[top]);
		
}

void display(int *p, int top)
{
	if(top == -1)
		printf("\n Stack is Empty");
	else
		for(int i = top; i>-1; i--)
			printf("\ndata -> %d",p[i]);

}
	

int main()
{
	int top = -1,opt;
	int *p = NULL;
	
	do
	{
		printf("\nOperation on Stack ");
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5 .Exit\n");
		printf("Enter Your Choice ");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1:
			p = push(p,&top);
			break;
			
			case 2:
			p = pop(p,&top);
			break;
			
			case 3:
			peek(p,top);
			break;
			
			case 4:
			display(p,top);
			break;
			
			case 5:
			exit (0);
		}
	}while(opt);
	
return 0;
}
