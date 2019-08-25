#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct tree{
   int data;
   struct tree *left;
   struct tree *right;
};

/*creation of new node*/
struct tree* newNode(int data)
{
    struct tree* node = (struct tree*)malloc(sizeof(struct tree));
    node->data = data;
    node->left= NULL;
    node->right= NULL;

    return node;
}



/* Finding Maximum depth*/
int maxDepth(struct tree* node)
{
   if (node==NULL)
       return 0;
   else
   {
       int ld = maxDepth(node->left);
       int rd = maxDepth(node->right);
 

       if (ld > rd)
           return(ld+1);
       else 
           return(rd+1);
   }
} 

int balanced(struct tree* root){

   if(root==NULL)
        return 1;
   else{
       int balfact;
       int left=maxDepth(root->left);
       int right=maxDepth(root->right);

       balfact=left-right;
       return balfact;  
   }
}
/* Rotation Code starts here*/

struct tree *rightRotate(struct tree *y)
{
    struct tree *x = y->left;
    struct tree *z = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = z;

    return x;
}

struct tree *leftRotate(struct tree *x)
{
    struct tree *y = x->right;
    struct tree *z = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = z;

    return y;
}

/* Code to insert node in a BST*/
struct tree* insert(struct tree* node, int data)
{
    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    
    int balance = balanced(node);
 
 
    // LL Case
    if (balance >1 && data < node->left->data)
        return rightRotate(node);
 
    // RR Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    // LR Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // RL Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 

     
/* Print nodes at a given level */
void printGivenLevel(struct tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        cout<<"  ";
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int print(struct tree* ptr,int n)
{   
       int i,j;
       for(i=1;i<=n;i++)
       {
          for(j=0;j<=n-i;j++)
              cout<<"  ";
          printGivenLevel(ptr, i);
          cout<<endl;
       }
     return 0;
}



int main()
{
  struct tree *root=NULL,*ptr;
  int n,data,i;
  cout<<"Enter no. of elements in AVL Tree=\n";
  cin>>n;

  for(i=0;i<n;i++){ 
     cin>>data;
     root=insert(root,data);
  }  

  cout<<"\n";
  print(root,n);

  return 0;
}

