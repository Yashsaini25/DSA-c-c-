#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_search_tree
{
    int val;
    struct binary_search_tree* left;
    struct binary_search_tree* right;
}bst;

void insert(bst**, int);
void get_new_node(bst**, int);
bst* delete(bst*, int);
bst* min(bst*);
bst* second_max(bst* root);
int common_parent(bst*);
int height(bst*);
int count_left(bst*);
void inorder(bst*);


int main()
{
    bst* root=NULL, *temp=NULL;;
    int ch,val;

    do
    {
        printf("\n1- Create Binary Search Tree\n2- Find a node with second highest value\n3- Delete a node form the tree\n4- Count the total number of nodes having common parent\n5- Find height\n6- Count total numbers of nodes from left hand side of the root node\n7- Display inorder\n8- Exit the program\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter a value to insert: ");
                scanf("%d",&val);
                insert(&root,val);
                break;
            case 2:
                temp=second_max(root);
                if(temp==NULL)
                printf("\n2nd maximum value not found\n");
                else printf("\n2nd maximum value: %d\n",temp->val);
                break;
            case 3:
                printf("\nEnter a value to delete: ");
                scanf("%d",&val);
                root=delete(root,val);
                break;
            case 4:
                val=common_parent(root);
                printf("\nNo. of nodes having common parent: %d\n",val);
                break;
            case 5:
                val=height(root);
                printf("\nHeight of tree: %d\n",val);
                break;
            case 6:
                val=count_left(root->left);
                printf("\nNo. of nodes from left hand side of the root node: %d\n",val);
                break;
            case 7:
                printf("\n");
                inorder(root);
                printf("\n");
                break;
            case 8:
                return 0;
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }while(ch!=8);
}


void insert(bst** root, int val)
{
    if(*root==NULL)
    get_new_node(root,val);

    else if(val < (*root)->val)
    insert(&((*root)->left),val);

    else if(val > (*root)->val)
    insert(&((*root)->right),val);
}


void get_new_node(bst** new_node,int val)
{
    *new_node=(bst*)malloc(sizeof(bst));
    if(new_node==NULL)
    {
        printf("\nMemory allocation failed\n");
        return;
    }

    (*new_node)->val=val;
    (*new_node)->left=NULL;
    (*new_node)->right=NULL;
}


bst* delete(bst* root, int val)
{
    if(root==NULL)
    return root;

    if(val < root->val)
    root->left=delete(root->left,val);

    else if(val > root->val)
    root->right=delete(root->right,val);

    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left==NULL)
        {
            bst* temp=root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL)
        {
            bst* temp=root->left;
            free(root);
            return temp;
        }
            
        bst* temp=min(root->right);
        root->val=temp->val;
        root->right=delete(root->right,temp->val);
    }
    return root;
}


bst* min(bst* root)
{
    if(root==NULL)
    return root;

    if(root->left==NULL)
    return root;

    return min(root->left);
}


bst* second_max(bst* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return NULL;

    bst* parent=NULL;
    bst* current=root;

    while(current->right!=NULL)
    {
        parent=current;
        current=current->right;
    }

    if(current->left!=NULL)
    {
        current=current->left;
        while(current->right!=NULL)
        current=current->right;

        return current;
    }
    return parent;
}


int common_parent(bst* root)
{
    if(root==NULL)
    return 0;

    if(root->left!=NULL && root->right!=NULL)
    return 2 + common_parent(root->left) + common_parent(root->right);

    return common_parent(root->left) + common_parent(root->right);
}


int height(bst* root)
{
    if(root==NULL)
    return -1;

    if(root->left==NULL && root->right==NULL)
    return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    return 1 + ((lh>rh) ? lh:rh);
}


int count_left(bst* root)
{
    if(root==NULL)
    return 0;

    return 1 + count_left(root->left) + count_left(root->right);
}


void inorder(bst* root)
{
    if(root == NULL)
    return;

    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
