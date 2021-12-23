//Inorder(Left Root Right) Preorder(Root Left Right) and Postorder(Left Right Root) Traversal

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
	struct  node *root = NULL;
	int x;
	
	root = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data : ");
	scanf("%d",&x);
	
	if(x == -1)
		return 0;
	
	root -> data = x;
	
	printf("\nEnter left child of %d",x);
		root -> left = create();
	
	printf("\nEnter right child of %d",x);
		root -> right = create();
	
	return root;
}

//inorder traversal
void inorder(struct  node *root)
{
	if(root == NULL)
		return;
		
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

//preorder traversal
void preorder(struct node *root)
{
	if (root == NULL)
		return ;
		
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

//postorder traversal
void postorder(struct node *root)
{
	if (root == NULL)
		return;
		
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}

int main()
{
	struct  node *root = NULL;
	root = create();//creating tree
	
	printf("\nInorder Traversal of Tree:\n");
	inorder(root);	//inorder traversal
	
	printf("\nPreorder Traversal of Tree:\n");
	preorder(root);	//preorder traversal
	
	printf("\nPostorder Traversal of Tree:\n");
	postorder(root);	//postorder traversal
	
	return 0;
}

