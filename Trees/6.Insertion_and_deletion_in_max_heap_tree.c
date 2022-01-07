//Insertion & deletion in a Max Heap Tree

#include<stdio.h>
#define MAX 1000	//max size of heap

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
	int parent = (i-1)/2;	//parent of the inserted key node
	
	if(arr[parent] > 0)
	{
		if(arr[i] > arr[parent])
		{
			swap(&arr[i],&arr[parent]);	//swap if parent is less than curent node data
			heapify(arr,n,parent);	//recursive call for the parent
		}
	}
}

void Dheapify(int arr[], int n , int i)
{
	int lar = i;		//initializing root as max
	int l = 2*i + 1;	//left child
	int r = 2*i + 2;	//right child
	
	if(l < n && arr[l] > arr[lar])		//if left child is larger
		lar = l;
	else if(r < n && arr[r] > arr[lar])	//if right child is larger
		lar = r;
	
	if(lar != i)				//if root is not the largest
	{				
		swap(&arr[i],&arr[lar]);	
		Dheapify(arr,n,lar);	//recursively Dheapify
	}	
}

void insertNode(int arr[], int *n, int key)
{
	*n = *n + 1;			//increase size by 1
	arr[(*n)-1] = key;		//inserting element at the end of array
	heapify(arr,*n,(*n)-1);	//appropriate position for node, bottom up approach
}

void deleteRoot(int arr[], int *n)
{
	int lastElement = arr[(*n)-1];
	arr[0] = lastElement;	//replacing root with last element
	*n = *n - 1; 			//decrement size of n by 1
	Dheapify(arr,*n,0);		//Dheapify the root node
}

void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i<n; i++)
		printf("%d\t",arr[i]);
	printf("\n\n");
}

int main()
{
	
	int arr[MAX] = {70,50,40,45,35,39,16,10,9};
	int key;
	int n = 9,i;
	printf("\nArray representation of heap\n");
	printArray(arr,n);
	
	while(1)
	{
		printf("Enter key to Insert in the tree and -1 to exit\n");
		scanf("%d",&key);
		if(key != -1)
			//heapify
			insertNode(arr,&n,key);
		else
			break;
	}
	printf("\n\nFinal Heap Tree is:\n\n ");
	
	printArray(arr,n);
	
	//Dheapify

	deleteRoot(arr,&n);
	
	printf("\n\nFinal Heap Tree After performing Deletion is:\n\n ");
	
	printArray(arr,n);
	
	
	return 0;
}
