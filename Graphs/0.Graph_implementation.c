//Graph Implementation 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct N
{
    struct N *next;
    struct ver *orig;
    int weight;
    int vertexno;
} node;

typedef struct ver
{

    int Data;
    node *pt;

} vertex;

typedef struct gra
{

    int v;
    vertex *arr;

} graph;

graph *create(int a)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->v = a;
    g->arr = (vertex *)malloc(sizeof(vertex) * a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter data of %d node :", i + 1);
        scanf("%d", &g->arr[i].Data);
        g->arr[i].pt = NULL;
    }
    return g;
}

void addconnection(graph *g, int sr, int des, int w)
{
    node *new = (node *)malloc(sizeof(node));
    new->orig = &(g->arr[des - 1]);
    new->weight = w;
    new->vertexno = des;
    node *temp = g->arr[sr - 1].pt;
    new->next = temp;
    g->arr[sr - 1].pt = new;
}

void print(graph *g)
{
    printf("\n\nGraph is :\n");
    for (int i = 0; i < g->v; i++)
    {
        printf("%d node data is %d and is connected to : \n", i + 1, g->arr[i].Data);
        node *temp = g->arr[i].pt;
        if (temp == NULL)
            printf("No other vertex\n");
        else
            while (temp)
            {
                printf("%d node (Data is %d) and weight of edge between them is %d \n", temp->vertexno, temp->orig->Data, temp->weight);
                temp = temp->next;
            }
        printf("\n");
    }
    printf("\n\n Graph is printed\n");
}

int main()
{
    int v;
    printf("Enter No. of Nodes/vertex of graph \n");
    scanf("%d", &v);
    graph *Graph = create(v);
    while (1)
    {
        int ch, sr, des, weight;
        printf("Enter 1 to add connection and 0 to exit:\n");
        scanf("%d", &ch);
        if (ch == 0)
            break;
        printf("Enter Node No.s to be connected and edge weight:\n");
        scanf("%d%d%d", &sr, &des, &weight);
        addconnection(Graph, sr, des, weight);
    }
    print(Graph);
    return 0;
}