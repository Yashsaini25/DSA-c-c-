#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *left, *right;
}bst;

typedef struct queue
{
    bst* data;
    struct queue* next;
}queue;

bst* get_new_node(int);
bst* insert(bst*,int);
void level_traversal(bst* root);
void enqueue(bst*, queue**, queue**);
bst* dequeue(queue**, queue**);

int main()
{
  int ch,v;
  bst* root=NULL;

  do
  {
    printf("\n1-Insert\n2-Display Level order Traversal\n3-Exit\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d",&v);
            root=insert(root,v);
            break;
        case 2:
            level_traversal(root);
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid choice\n");
        }
    }while(ch!=3);
    
return 0;
}


bst* get_new_node(int v)
{
    bst* new_node=(bst*)malloc(sizeof(bst));

    new_node->data=v;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}


bst* insert(bst* root, int v)
{
    if(root==NULL)
    return get_new_node(v);

    else
    {
        if(v < (root)->data)
        root->left=insert(root->left,v);

        else if(v > (root)->data)
        root->right=insert(root->right,v);
    }   
    return root;
}


void level_traversal(bst* root)
{
    if(root==NULL)
    return;

    queue* f=NULL, *r=NULL;
    enqueue(root,&f,&r);

    while(f!=NULL)
    {
        bst* p=dequeue(&f,&r);
        printf("%d ",p->data);

        if(p->left!=NULL)
        enqueue(p->left,&f,&r);

        if(p->right!=NULL)
        enqueue(p->right,&f,&r);
    }
}


void enqueue(bst* root, queue** f, queue** r)
{
    queue* q=(queue*)malloc(sizeof(queue));

    if(*r==NULL)
    *f=q;

    else (*r)->next=q;

    q->data=root;
    q->next=NULL;

    *r=q;
}


bst* dequeue(queue** f, queue** r)
{
    bst* temp1=(*f)->data;
    queue* temp2=*f;

    *f=(*f)->next;

    if(*f==NULL)
    *f=*r=NULL;

    free(temp2);
    return temp1;
}