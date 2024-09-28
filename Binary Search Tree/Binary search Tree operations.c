#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree
{
 int data;
 struct binary_search_tree *left, *right;
}bst;

bst* get_new_node(int);
bst* insert(bst*,int);
int FindHeight(bst*);
bst* Find_min(bst*);
bst* Find_max(bst*);
int leaf_node(bst*);
int total_node(bst*);
int search(bst*, int);
bst* delete(bst*, int);
void range_elements(bst*, int, int);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);

int main()
{
  int ch,v,h,f,key,n,low,high;
  bst* root=NULL,*min=NULL,*max=NULL;

  do
  {
    printf("\n1-Insert\n2-Find Height\n3-Find minimum element\n4-Find maximum element\n5-Count total no. of leaf nodes\n6-Count total no. of nodes\n7-Delete a element\n8-Search a particular element\n9-Display elements b/w a particular range\n10-Display Preorder\n11-Display Inorder\n12-Display Postorder\n13-Exit\n\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter a value to insert: ");
            scanf("%d",&v);
            root=insert(root,v);
            break;
        case 2:
            h=FindHeight(root);
            printf("\n%d\n",h);
            break;
        case 3:
            min=Find_min(root);
            if(min==NULL)
            printf("\nTree is empty");
            else printf("\nMinimum element: %d",min->data);
            printf("\n");
            break;
        case 4:
            max=Find_max(root);
            if(max==NULL)
            printf("\nTree is empty");
            else printf("\nMaximum element: %d",max->data);
            printf("\n");
            break;
        case 5:
            n=leaf_node(root);
            printf("\nTotal no. of leaf nodes: %d\n",n);
            break;
        case 6:
            n=total_node(root);
            printf("\nTotal no. of nodes: %d\n",n);
            break;
        case 7:
            printf("\nEnter the element to delete: ");
            scanf("%d",&key);
            root=delete(root,key);
            break;
        case 8:
            printf("\nEnter the element to find: ");
            scanf("%d",&key);
            f=search(root,key);
            if(f==0)
            printf("\nElement not found\n");
            if(f==1)
            printf("\nElement found\n");
            break;
        case 9:
            printf("\nEnter the range: ");
            scanf("%d %d",&low,&high);
            range_elements(root,low,high);
            printf("\n");
            break;
        case 10:
            preorder(root);
            printf("\n");
            break;
        case 11:
            inorder(root);
            printf("\n");
            break;
        case 12:
            postorder(root);
            printf("\n");
            break;
        case 13:
            return 0;
        default:
            printf("\nInvalid choice\n");
        }
    }while(ch!=13);
    
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


int FindHeight(bst* root) 
{
    if(root == NULL)
    return -1;

    int lh=FindHeight(root->left);
    int rh=FindHeight(root->right);

    return (lh>rh ? lh : rh) +1;
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


int leaf_node(bst *root)
{
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return 1;

    return leaf_node(root->left) + leaf_node(root->right);
}


int total_node(bst *root)
{
    if(root==NULL)
    return 0;

    return 1 + total_node(root->left) + total_node(root->right);
}


bst* delete(bst* root, int key)
{
    if(root==NULL)
    return root;

    else if(key < root->data)
    root->left=delete(root->left,key);

    else if(key > root->data)
    root->right=delete(root->right,key);

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

        bst* temp=Find_min(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
        return root;
}


int search(bst* root, int key)
{
    if(root==NULL)
    return 0;

    while(root!=NULL)
    {
        if(key==root->data)
        return 1;

        if(key < root->data)
        root=root->left;

        else root=root->right;
    }
    return 0;
}


void range_elements(bst* root, int low, int high)
{
    if(root==NULL)
    return;

    if(low < root->data)
    range_elements(root->left,low,high);

    if(root->data >= low && root->data <= high)
    printf("%d ",root->data);

    if(high > root->data)
    range_elements(root->right,low,high);
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
 
 
 

