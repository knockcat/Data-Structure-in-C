//Depth First Search using adjacency matrix

#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0,0,0,0,0,0,0};
    // 7 by 7 adjacency Matrix
    int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

void DFS(int i)
{
	int j;
	printf("%d",i);
	visited[i] = 1;
	for( j = 0; j<7; j++)
	{
		if(A[i][j] == 1 && !visited[j])
		{
			DFS(j);
		}
	}
}

int main(){
    // DFS Implementation 
	DFS(0);
    return 0;
}

