// dynamic Queue half double func
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int capacity;
    int front;
    int rear;
    int *arr;
};

struct Queue *create_Queue(int cap);
int IsEmptyQueue(struct Queue *p);
int IsFullQueue(struct Queue *p);
int Qcapacity(struct Queue *p);
void DoubleQ(struct Queue *p);
void HalfQ(struct Queue *p);
void EnQueue(struct Queue *p, int value);
void DeQueue(struct Queue *p);
void Display(struct Queue *p);
struct Queue *DeleteQ(struct Queue *p);


int menu()
{
    int choice;
    
    printf("\n1. See Status  of Queue : ");
    printf("\n2. EnQueue (Insert an element in the Queue): ");
    printf("\n3. DeQueue (Delete an element from the queue) : ");
    printf("\n4. Display : ");
    printf("\n5. End Program");
    
    printf("\n\nEnter your CHoice ");
    scanf("%d", &choice);

    system("cls");//clear Function

    return choice;
}

int main()
{
    struct Queue *p;
    int value;
    p = create_Queue(4);

    while (1)
    {
        switch (menu())
        {
        case 1:
            printf("\nCapacity : %d ", Qcapacity(p));
            printf("\nFront : %d , Rear : %d ", p->front, p->rear);

            break;
        case 2:
            printf("\nEnter Element : ");
            scanf("%d", &value);
            EnQueue(p, value);
            break;
        case 3:
            DeQueue(p);
            break;
        case 4:
           Display(p);
            break;
        case 5:
            p = DeleteQ(p);
            exit(0);
            break;

        default:
            printf("\nInvlaid Choice , retry : ");
            break;
        }
    }
}

struct Queue *create_Queue(int cap)
{
    struct Queue *temp = NULL;
    temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->capacity = cap;
    temp->front = -1;
    temp->rear = -1;
    temp->arr = (int *)malloc(sizeof(int) * temp->capacity);

    return temp;
}

int IsEmptyQueue(struct Queue *p)
{
    if (p->front == -1)
        return 1;
    else
        return 0;
}

int IsFullQueue(struct Queue *p)
{
    if (p->front == 0 && p->rear == p->capacity - 1)
        return 1;
    else if (p->front == p->rear + 1)
        return 1;
    else
        return 0;
}

int Qcapacity(struct Queue *p)
{
    return p->capacity;
}

void DoubleQ(struct Queue *p)
{
    int i, j;
    int *temp;
    p->capacity = p->capacity * 2;
    temp = (int *)malloc(sizeof(int) * p->capacity);

    for (i = p->front, j = 0; i != p->rear; j++)
    {
        temp[j] = p->arr[i];
        if (i == p->capacity / 2 - 1 && p->rear != -1)
            i = 0;
        else
            i++;
    }

    free(p->arr);
    p->arr = temp;
    p->front = 0;
    p->rear = p->capacity / 2 - 1;
}

void HalfQ(struct Queue *p)

{
    int *temp;
    int i, j, l;
    temp = (int *)malloc(sizeof(int) * (p->capacity / 2));
    l = p->capacity / 2;
    for (i = 0, j = p->front; i < l; i++)
    {
        temp[i] = p->arr[j];
        if (j == p->capacity - 1)
        {
            j = 0;
        }
        else
        {
            j++;
        }
    }
    free(p->arr);
    p->arr = temp;
    p->capacity = l;
    p->front = 0;
    p->rear = l - 1;
}

void EnQueue(struct Queue *p, int value)
{
    if (p->capacity < 1)
    {
        printf("Invalid Capacity");
    }

    else
    {
        // if(p -> front == -1 && p -> rear = -1)
        if (IsEmptyQueue(p))
        {
            p->arr[0] = value;
            p->front = 0;
            p->rear = 0;
        }
        else if (IsFullQueue(p))
        {
            DoubleQ(p);
            p->rear = p->rear + 1;
            p->arr[p->rear] = value;
        }

        else
        {
            if (p->rear == p->capacity - 1)
                p->rear = 0;
            else
                p->rear = p->rear + 1;
            p->arr[p->rear] = value;
        }
    }
}

void DeQueue(struct Queue *p)
{
    int i, size = 0;

    if (IsEmptyQueue(p))
    {
        printf("\nUnderFlow");
    }

    else if (p->front == p->rear)
    {
        p->front = p->rear = -1;
    }

    else if (p->front == p->capacity - 1)
    {
        p->front = 0;
    }

    else
    {
        p->front = p->front + 1;
    }

    if (p->front > -1)
    {
        for (i = p->front; i != p->rear;)
        {
            size++;
            if (i == p->capacity - 1)
                i = 0;
            else
                i++;
        }
        size++;

        if (size == p->capacity / 2)
            HalfQ(p);
    }
}

struct Queue *DeleteQ(struct Queue *p)
{
    free(p->arr);
    free(p);
    return (NULL);
}

void Display(struct Queue *p)
{
    for(int i = p->front ; i<= p->rear ; i++)
    {
        printf("\ndata %d at index %d\n", p->arr[i], i);
    }
}