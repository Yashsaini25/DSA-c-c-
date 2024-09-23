#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *left, *right;
}bst;

bst* get_new_node(int);
bst* insert(bst*,int);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);

int main()
{
  int ch,v;
  bst* root=NULL;

  do
  {
    printf("\n1-Insert\n2-Display Preorder\n3-Display Inorder\n4-Display Postorder\n5-Exit\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d",&v);
            root=insert(root,v);
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            return 0;
        default:
            printf("\nInvalid choice\n");
        }
    }while(ch!=5);
    
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
    

void preorder(bst* root)
{
    if(root==NULL)
    return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(bst* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


void postorder(bst* root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
 
 
 

