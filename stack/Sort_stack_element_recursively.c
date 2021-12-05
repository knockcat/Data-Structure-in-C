// Program to Sort Stack Elements using a Recursive Function
#include<stdio.h>
#define cap1 100
#define cap2 100
int p_stack[cap1];
int t_stack[cap2];
int sizep=0;
int sizet=0;
int top=-1;
int top1=-1;
void push_p(int x)
{
	if(top>cap1)
	{
		printf("top overflow condition\n");
	}
	else {
		top++;
		sizep++;
		p_stack[top]=x;
	}
}
void pop_p()
{
	if(top==-1)
	{
	printf("undererflow condition\n");	
	}
	else 
	{
	top--;
	sizep--;
}
}
void push_t(int x)
{
	if(top1>cap2)
	{
		printf("top1 overflow condition\n");
	}
	else {
		top1++;
		sizet++;
		t_stack[top1]=x;
	}
}
void pop_t()
{
	if(top1==-1)
	{
	printf("undererflow condition\n");	
	}
	else 
	{
	top1--;
	sizet--;
}
}
void sort()
{
    if(top==-1)
    {
    	return;
	}
	else if(top1==-1)
	{
		push_t(p_stack[top]);
		pop_p();
	}
	else if(p_stack[top]>t_stack[top1])
	{
		push_t(p_stack[top]);
		pop_p();
	}
	else if(p_stack[top]<t_stack[top1])
	{
	int ele=p_stack[top];
	pop_p();
	while(ele<t_stack[top1] && top1!=-1)
	{
		push_p(t_stack[top1]);
		pop_t();
	}
	push_t(ele);
}
sort();
}
int main()
{
	int n;
	printf("enter no of elements of stack\n");
	scanf("%d",&n);
    printf("\nEnter Elements\n");
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		push_p(temp);
	}
	sort();
	for(int i=top1;i>=0;i--)
	{
		push_p(t_stack[i]);
	}
	for(int i=top1;i>=0;i--)
	{
		printf("%d ",p_stack[i]);
	}
	printf("\nTop = %d\nSize = %d\n",top,sizep);
}