#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int weight,vertex;
    struct node* next;
}node;

typedef struct graph
{
    struct node** lists;
}graph;

typedef struct queue
{
    struct node** info;
    struct queue* next;
}queue;

graph* create_graph(int);
node* create_node(int, int);
void add_edge(graph*, int, int, int);
void BFS(graph*, int, int);
void DFS(graph*, int, int);

int main()
{
    int num;
    printf("Enter the no. of vertices: ");
    scanf("%d",&num);
    graph* gr=create_graph(num);

    int ch, src, dst,wt,start;

    do {
        printf("\n1-Add Edge\n2-Display BFS\n3-Display DFS\n4-Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1:
                printf("Enter source, destination, and weight of edge: ");
                scanf("%d %d %d", &src, &dst, &wt);
                if (src < num && dst < num) {
                    add_edge(gr, src, dst, wt);
                } else {
                    printf("Invalid vertex.\n");
                }
                break;
            case 2:
                printf("\nEnter the vertex from where you want to start: ");
                scanf("%d",&start);
                BFS(gr,num,start);
                break;
            case 3:
                printf("\nEnter the vertex from where you want to start: ");
                scanf("%d",&start);
                DFS(gr,num,start);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}


graph* create_graph(int num)
{
    graph* gr=(graph*)malloc(sizeof(graph));
    gr->lists=(node**)malloc(num*sizeof(node*));

    for(int i=0;i<num;i++)
    gr->lists[i]=NULL;

    return gr;
}


node* create_node(int vertex, int weight)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->weight=weight;
    new_node->vertex=vertex;
    new_node->next=NULL;

    return new_node;
}


void add_edge(graph* gr, int src, int dst, int wt)
{
    node* new_node=create_node(dst,wt);
    new_node->next=gr->lists[src];
    gr->lists[src]=new_node;

    new_node=create_node(src,wt);
    new_node->next=gr->lists[dst];
    gr->lists[dst]=new_node;
}


void BFS(graph* gr, int num, int start)
{
    int* visited=(int*)calloc(num,sizeof(int));
    int* queue=(int*)malloc(num*sizeof(int));

    int i,front=-1,rear=-1;
    visited[start]=1;
    queue[++rear]=start;

    printf("\n");
    while(front<rear)
    {
        int current=queue[++front];
        printf("%d ",current);

        node* temp=gr->lists[current];
        while(temp!=NULL)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex]=1;
                queue[++rear]=temp->vertex;
            }
            temp=temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(queue);
}


void DFS(graph* gr, int num, int start)
{
    int* visited=(int*)calloc(num,sizeof(int));
    int* stack=(int*)malloc(num*sizeof(int));

    int i,top=-1;
    visited[start]=1;
    stack[++top]=start;

    printf("\n");
    while(top>=0)
    {
        int current=stack[top--];
        printf("%d ",current);

        node* temp=gr->lists[current];
        while(temp!=NULL)
        {
            if(!visited[temp->vertex])
            {
                visited[temp->vertex]=1;
                stack[++top]=temp->vertex;
            }
            temp=temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(stack);
}



