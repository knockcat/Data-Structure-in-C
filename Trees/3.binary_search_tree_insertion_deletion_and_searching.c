//Binary Search Tree (Insertion Deletion Searching)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

//allocating memory for a node
struct node *createNode(int data)
{
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return root;
}

//Insert in a Binary Search Tree
struct node *InsertInBST(struct node *root, int key)
{
    if(root == NULL)
        return createNode(key);
    if(key < root->data)
        root->left =  InsertInBST(root->left,key);
    else if(key > root->data)
    {
        root ->right =  InsertInBST(root->right,key);
    }
    return root;
}

//search data in a Binary Search Tree
struct node *searchInBST(struct node * root, int key)
{
        if(root->data == key)
            return root;
            
        //data > key
        if(root->data > key)
        {
               return searchInBST(root->left,key);
        }
		
		//data < key
        return searchInBST(root->right,key);
        
}

//func for finding inorder successor of a tree
struct node* inorderSucc(struct node *root)
{
    struct node *curr = root;
    while(curr && curr->left != NULL)
    {
        curr = curr  -> left;
    }
    return curr;
}

//del in a binary search tree
struct node *delInBST(struct node *root, int key)
{
    if(key < root->data)
        root -> left = delInBST(root->left,key);
    else if(key > root->data)
        root-> right = delInBST(root->right,key);
    else{
    	
 		//for 0 and 1 node
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        } 

        else if(root->right == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

		//node have two child
        struct node *temp = inorderSucc(root->right);
        root->data = temp -> data;
        root->right = delInBST(root->right,temp->data);

    }

    return root;
       
}

//for printing data ( inorder traversal)
void inorder(struct node *root)
{
	if(root == NULL)
		return;
    inorder(root->left); 
    printf("%d\t",root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    root = InsertInBST(root,1);	//Insert in a BST
    root = InsertInBST(root,54);
    root = InsertInBST(root,5);
    root = InsertInBST(root,13);
    root = InsertInBST(root,89);
    if(searchInBST(root,5) == NULL)	//search in a BST
    	printf("\nKey doesn't exist...\n");
    else{
    	printf("\nkey Exist\n");
	}
    
    inorder(root);
    root = delInBST(root,5);	//Delete in a BST
    root = delInBST(root,89);
    printf("\nAfter Deletion\n");
     inorder(root);
    return 0;
}
