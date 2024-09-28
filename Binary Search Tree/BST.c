#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *left, *right;
}bst;

void insert(bst**);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);

int main()
{
  int ch;
  bst* root=NULL;

  do
  {
    printf("\n1-Insert\n2-Display Preorder\n3-Display Inorder\n4-Display Postorder\n5-Exit\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insert(&root);
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


void insert(bst** root)
{
    int v;

    bst* new_node=(bst*)malloc(sizeof(bst));
    if(!new_node)
    {
        printf("\nMemory allocation failed\n");
        return;
    }

    else
    {
        printf("\nEnter a value to insert: ");
        scanf("%d",&v);
        new_node->data=v;

        if(*root==NULL)
        *root=new_node;

        else
        {
            bst* temp=*root;
            bst* parent=NULL;

            while(temp!=NULL)
            {
                parent=temp;

                if(v < temp->data)
                temp=temp->left;

                else if(v > temp->data)
                temp=temp->right;
            }

            if(v < parent->data)
            parent->left = new_node;
        
            if(v > parent->data)
            parent->right = new_node;
        }
        new_node->left=NULL;
        new_node->right=NULL;
    }   
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
 
 
 

