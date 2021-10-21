/*program to implement priority queue where each element is associated with an priority number.
 Here insertion will be done from rear counter but, deletion will be done based on the priority.*/

#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int choice;
    printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.Display\n5.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    return choice;
}

void enqueue(int *queue, int *front, int *rear, int size)
{
    int data;
   if(*rear == -1 && *front == -1)
    {
        *front = *rear = 0;
        
        printf("\nEnter data : ");
        scanf("%d",&data);
        
        queue[*rear] = data;
    }

    else if((((*rear) + 1) % size) == *front  )
    {
        printf("Queue is Full");
    }
    else{
        
        printf("\nEnter data : ");
        scanf("%d",&data);
        *rear = ((*rear) + 1) % size;
        queue[*rear] = data;
    }
       
     
    
}

int dequeue(int *queue, int *front, int *rear, int size)
{
    int del;
    if(*rear == -1 && *front == -1){
        printf("\nQueue is Empty");
        return 0;
    }
    else if (*front == *rear)
    {
        del = queue[*front];
        *front = *rear = -1;
        return del;
    }
    else
    {
        del = queue[*front];
        *front = ((*front) + 1) % size;
        return del;
    }
        
    
    
}

void peek(int *queue, int *front, int *rear)
{
    if(*front == -1 && *rear == -1 )
    {
        printf("\nQueue is Empty");
    }
    else{
    printf("\nPeek Element is : %d",queue[*front]);
    }
}

void display(int *queue, int *front, int *rear,int size)
{
    if(*front == -1 && *rear == -1)
        printf("\nQueue is Empty");
int i = *front;

    while(i != *rear)
    {
        printf("\ndata is : %d at index %d",queue[i],i);
        i = (i + 1) % size;
    }printf("\ndata is : %d at index %d",queue[i],i);
}

void sort(int *queue, int *front, int *rear,int size)
{
    //printf("Knockcat this side");
    int max = INT_MIN;
    {
        for(int i=*front;i<*rear;i=(i+1)%size){
            if(queue[i]>= max)
            {
                int temp = queue[i];
                queue[i] = queue[i+1];
                queue[i+1] = temp;
            }
        }
    }
}

int main()
{
    int size, choice;
    int queue[size];
    printf("Enter Size : ");
    scanf("%d", &size);

    int front = -1, rear = -1, del;
    while (1)
    {
            choice = menu();
    printf("\n front = %d and rear = %d\n",front,rear);
            switch (choice)
        {
        case 1:
            enqueue(queue, &front, &rear, size);
            break;

        case 2:
            del = dequeue(queue, &front, &rear, size);
            printf("\nDequeued element is : %d", del);
            break;

        case 3:
            peek(queue, &front,&rear);
            break;

        case 4:
            display(queue, &front, &rear,size);
            break;

        case 5:
            exit(1);
            break;
        }
        sort(queue,&front,&rear,size);
    }
}
