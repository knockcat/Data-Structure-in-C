//Intersection of 2 Stack

#include<stdio.h>
#include<stdlib.h>

int main()
{

	int m,n; //m rows and n columns 
	printf("\n Enter ROw and colum\n");
	scanf("%d%d",&m,&n);
	
	int *ptr = (int*)malloc((m*n)*sizeof(int));
	
	for(int i = 0; i<m; i++)
	{
		for (int j = 0; j < n; j++)
		{
            		scanf("%d", ((ptr+i)+j));
            	}
	}//(*(matrix + i) + j))
	
	  for(int i = 0; i<m; i++)
	{
		for (int j = 0; j < n; j++)
		{
            		printf("%d\t", *((ptr+i)+j));
            	}printf("\n");
	}
	int mean;
	
	printf("\nMean values\n");
	
	for(int i = 0; i<n; i++)
	{mean = 0;
		for(int j = 0; j<n; j++)
		{
			mean += *((ptr+j)+i);
		}
		
	printf("%d",mean);
	printf("\n");
	}
	return 0;
}
