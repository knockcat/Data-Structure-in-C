//AVL TREE Insertion (Self Balancing Tree)

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int key;
	struct node *right;
	struct node *left;
	int height;	// for balance factor
};

//for calculating height of any tree
int getHeight(struct node  *n)
{
	if (n == NULL)
		return 0;
	return n -> height;
}

//allocating memory for a node
struct node *createNode(int key)
{
	struct node* root  = (struct node*) malloc(sizeof(struct node));
	root -> key = key;
	root -> left = NULL;
	root -> right = NULL;
	root ->height = 1;
	
	return root;
}

//return max value of 2
int max(int a, int b)
{
	return (a>b) ? a : b;
}

//for finding balance factor
int getBalanceFactor(struct node *n)
{
	if(n == NULL)
		return 0;
		
	//return (n->left->height) - (n->right->height);	
	return getHeight(n->left) - getHeight(n->right);
}	

//right rotation
struct node *rightRotate(struct node *y)
{
	struct node *x = y -> left;
	struct node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	//updating heights
	x->height = max(getHeight(x->right),getHeight(x->left)) + 1;
	y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
	
	return x;   //x is now root node
	
}

//left rotation
struct node *leftRotate(struct node *x)
{
	struct node *y = x -> right;
	struct node *T2 = y->left;
	y->left = x;
	x->right = T2;
	
	//updating heights
	x->height = max(getHeight(x->right),getHeight(x->left)) + 1;
	y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
	
	return y;   //x is now root node
	
}

//insertion in BST & balancing tree
struct node* insert(struct node *root , int key)
{
	if(root == NULL)
		return createNode(key);
	if(key < root -> key)
		root->left = insert(root->left , key);
	else if(key > root->key)
		root->right = insert(root->right, key);
	
	root->height = 1 + max(getHeight(root->left),getHeight(root->right));
	int bal_fact = getBalanceFactor(root);
	
	//Left Left Case
	if(bal_fact > 1 && key < root->left->key)
		return rightRotate(root);
		
	//Right Right Case
	if(bal_fact < -1 && key > root->right->key) 
		return leftRotate(root);
		
	//Left Right Case
	if(bal_fact > 1 && key > root->left->key) 
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//Right Left Case
	if(bal_fact < -1 && key < root->right->key) 
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}

//for printing data ( preorder traversal)
void preorder(struct node *root)
{
	if(root == NULL)
		return;
	
	printf("%d\t",root->key);
	preorder(root->left);
	preorder(root->right);
	
}

int main()
{
	struct node *root = NULL;
	root =insert(root,23);	//insert in a BST  (avl self balance)
	root = insert(root ,78);
	root = insert(root,56);
	root = insert(root ,45);
	root = insert(root,123);
	root = insert(root ,8);
	preorder(root);
return 0;
}
