//Infix to prefix

#include<stdio.h>
#include<ctype.h>
#include<string.h>
# define max 100

void push(char stack[],int *top,char c)
{
	if(*top==max-1)
		printf("Overflow\n");
	else
		stack[++(*top)]=c;
}
char pop(char stack[], int *top)
{
	if(*top==-1)
		printf("Underflow\n");
	else
		return stack[(*top)--];
}
int priority(char c)
{
	if(c==')')
		return 0;
	if(c=='+'||c=='-')
		return 1;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	if(c=='^')
		return 3;
}
void display(char stack[],int top)
{
	while(top>-1)
		printf(" %c",stack[top--]);
	printf("\n");
}
void main()
{
	char infix[max],prefix[max],stack[max];
	int top=-1,i=0,j=0;
	printf("Enter infix: ");
	scanf("%s",infix);
	for(i=strlen(infix)-1;i>=0;i--)
	{
		char c=infix[i];
		if(isalnum(c))
			prefix[j++]=c;
		else if(top==-1||c==')')
			push(stack,&top,c);
		else if(c=='(')
			{
			    while(stack[top]!=')')
				prefix[j++]=pop(stack,&top);
			char w=pop(stack,&top);
			}
		else if(stack[top]=='^' && c=='^')
			{
			    prefix[j++]=pop(stack,&top);
			    push(stack,&top,c);
			}
		else 
			{
			    while(priority(stack[top])>priority(c))
				prefix[j++]=pop(stack,&top);
				push(stack,&top,c);
			}
	}
	while(top>-1)
		prefix[j++]=pop(stack,&top);
	prefix[j]='\0';
	for(i=strlen(prefix)-1;i>=0;i--)
	printf("%c",prefix[i]);
}

