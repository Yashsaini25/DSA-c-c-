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

graph* create_graph(int);
node* create_node(int, int);
void add_edge(graph*, int, int, int);
void print(graph*, int);

int main()
{
    int num;
    printf("Enter the no. of vertices: ");
    scanf("%d",&num);
    graph* gr=create_graph(num);

    int ch, src, dst,wt;

    do {
        printf("\n1-Add Edge\n2-Print Graph\n3-Exit\n");
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
                print(gr,num);
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 3);

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


void print(graph* gr, int num)
{
    for(int i=0;i<num;i++)
    {
        node* temp=gr->lists[i];
        printf("\nvertex: %d- ",i);

        while(temp)
        {
            printf("destination: %d, weight: %d\n",temp->vertex, temp->weight);
            printf("\t   ");
            temp=temp->next;
        }
        printf("\n");
    }
}