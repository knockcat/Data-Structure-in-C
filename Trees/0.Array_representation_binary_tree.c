// Binary Tree (Array Representation)

// 0 - Based Indexing
// for a node Tree[i] : Left Child = Tree[(2*i)+1] & Right Child = Tree[(2*i)+2] & Parent is at Tree[(i-1)/2]


// 1 - Based Indexing
// for a node Tree[i] : Left Child = Tree[(2*i)] & Right Child = Tree[(2*i)+1] & Parent is at Tree[i/2]

/*
                A
               / \
              B   C
             / \  / \
             D  E F  G
            / \ /
           H  I J
*/

#include<stdio.h>
#define size 10

char Tree[size];

int main()
{
    printf("Enter Node Values Level by Level : \n");
    
    for(int i = 0; i<size; ++i)
    {
        scanf("%c",&Tree[i]);
    }
    
    for(int i = 0; i<size; ++i)
        printf("%c ",Tree[i]);
    
    printf("\n\n");

    for(int i = 0; i<size; ++i)
    {
        if(i - 1 <  0)
            printf("[Root Node] Parent Doesn't Exist for this Node %c\n\n",Tree[i]);
        else
            printf("Parent Node of Current Node %c is %c\n\n",Tree[i],Tree[(i - 1) / 2]);
        
        if(((2*i) + 1) < size)    
            printf("Left Child of Current Node %c is %c\n\n",Tree[i],Tree[( 2 * i ) + 1]);
        else
            printf("Left Child of Current Node %c Doesn't Exist\n\n",Tree[i]);
         
        if(((2*i) + 2) < size)  
            printf("Right Child of Current Node %c is %c\n\n",Tree[i],Tree[( 2 * i) + 2]);
        else
            printf("Left Child of Current Node  %c Doesn't Exist\n\n",Tree[i]);
    }
    
    return 0;
}
