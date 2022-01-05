//Threaded Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct bstt
{
    int data;
    bool thread;
    struct bstt *left;
    struct bstt *right;
} bst;

bst *insert(bst *root, int Data)
{
    if (root == NULL)
    {
        bst *new = (bst *)malloc(sizeof(bst));
        new->data = Data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if (Data >= root->data)
        root->right = insert(root->right, Data);
    else if (Data < root->data)
        root->left = insert(root->left, Data);
    return root;
}

void display(bst *root)
{
    if (root == NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
    return;
}

bst *findINorder(bst *root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    return findINorder(root->right);
}

void thread(bst *root)
{
    if (root == NULL)
        return;
    thread(root->left);
    bst *inPred = findINorder(root->left);
    if (inPred != NULL)
    {
        inPred->thread = 1;
        inPred->right = root;
    }
    thread(root->right);
}

bst *leftMost(bst *n)
{
    if (n == NULL)
        return NULL;

    while (n->left != NULL)
        n = n->left;

    return n;
}

void inOrder(bst *root)
{
    bst *temp = leftMost(root);
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->thread)
            temp = temp->right;
        else
            temp = leftMost(temp->right);
    }
}

int main()
{
    int Data;
    bst *root = NULL;
    while (1)
    {
        printf("Enter your choice 1 to add , 0 to exit \n");
        scanf("%d", &Data);
        if (Data == 0)
            break;
        printf("Enter your Node Data : ");
        scanf("%d", &Data);
        root = insert(root, Data);
    }
    
    printf("\n\nInorder Traversal\n\n");
    display(root);
    
    printf("\n");
    
    thread(root);
    printf("\n\nThreaded Tree\n\n");
    inOrder(root);
    return 0;
}
