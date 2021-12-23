//binary tree implementation

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

//create function
struct node *create()
{
	int x;
	struct node *ptr = NULL;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data : ");
	scanf("%d",&x);
	
	if(x == -1)
		return 0;
	else
	{
		ptr -> data = x;
	
		printf("\nEnter left child of %d",x);
				ptr -> left = create();		//recursive call
			
		printf("\nEnter right child of %d",x);
				ptr -> right = create();	//recursive call
				
		return ptr;
		}
}

//for printing data preorder traversal
void preorder(struct  node *root){
	if(root == NULL)
		return ;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	struct node *root = NULL;
	root = create();
	preorder(root);
}
