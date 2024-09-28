#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *left, *right;
}bst;

bst* get_new_node(int);
bst* insert(bst*,int);
bst* Find_min(bst*);
bst* Find_max(bst*);
bst* search(bst*, int);
bst* successor(bst*, int);
bst* predecessor(bst*, int);
bst* ancestor(bst*,int,int);
void inorder(bst*);

int main()
{
  int ch,v,n1,n2;
  bst* root=NULL,*min=NULL,*max=NULL,*find=NULL;

  do
  {
    printf("\n1-Insert\n2-Find successor of a element\n3-Find Predecessor of a element\n4-Find lowest common ancestor of two nodes\n5-Display Inorder\n6-Exit\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d",&v);
            root=insert(root,v);
            break;
        case 2:
            printf("\nEnter a value: ");
            scanf("%d",&v);
            find=successor(root,v);
            if(find==NULL)
            printf("\nSuccessor not present\n");
            else printf("\n%d\n",find->data);
            break;
        case 3:
            printf("\nEnter a value: ");
            scanf("%d",&v);
            find=predecessor(root,v);
            if(find==NULL)
            printf("\nPredecessor not present\n");
            else printf("\n%d\n",find->data);
            break;
        case 4:
            printf("\nEnter 2 values: ");
            scanf("%d %d",&n1,&n2);
            find=ancestor(root,n1,n2);
            if(find!=NULL)
            printf("\n%d\n",find->data);
            break;
        case 5:
            inorder(root);
            printf("\n");
            break;
        case 6:
            return 0;
        default:
            printf("\nInvalid choice\n");
        }
    }while(ch!=6);
    
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
    

bst* Find_min(bst* root)
{
    if(root==NULL)
    return NULL;
    
    else if(root->left==NULL)
    return root;

    return Find_min(root->left);
}


bst* Find_max(bst* root)
{
    if(root==NULL)
    return NULL;
    
    else if(root->right==NULL)
    return root;

    return Find_max(root->right);
}


bst* search(bst* root, int key)
{
    if(root==NULL)
    return NULL;

    while(root!=NULL)
    {
        if(key==root->data)
        return root;

        if(key < root->data)
        root=root->left;

        else root=root->right;
    }
    return NULL;
}


bst* successor(bst* root, int k)
{
    bst* current=search(root,k);
    if(current==NULL)
    return NULL;

    if(current->right!=NULL)
    return Find_min(current->right);

    else
    {
        bst* successor=NULL;
        bst* ancestor=root;

        while(ancestor!=current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }

            else ancestor=ancestor->right;
        }
        return successor;
    }
}


bst* predecessor(bst* root, int k)
{
    bst* current=search(root,k);
    if(current==NULL)
    return NULL;

    if(current->left!=NULL)
    return Find_max(current->left);

    else
    {
        bst* predecessor=NULL;
        bst* ancestor=root;

        while(ancestor!=current)
        {
            if(current->data > ancestor->data)
            {
                predecessor=ancestor;
                ancestor=ancestor->right;
            }

            else ancestor=ancestor->left;
        }
        return predecessor;
    }
}


bst* ancestor(bst* root, int node1, int node2)
{
    if(root==NULL)
    return root;

    if(node1 < root->data && node2 < root->data)
    return ancestor(root->left, node1, node2);

    if(node1 > root->data && node2 > root->data)
    return ancestor(root->right, node1, node2);

    return root;
}


void inorder(bst* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}