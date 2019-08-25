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

/* Code to insert node in a BST*/
void insert(struct tree *root,int data){
     if(root==NULL)
          return;
     else{
         if(data<root->data){
                if(root->left==NULL){
                     struct tree *ptr=(struct tree *)malloc(sizeof(struct tree));
                     ptr->data=data;
                     ptr->left=ptr->right=NULL;
                     root->left=ptr;
                }
                else
                   insert(root->left,data);
          }
          else{
               if(root->right==NULL){
                     struct tree *ptr=(struct tree *)malloc(sizeof(struct tree));
                     ptr->data=data;
                     ptr->left=ptr->right=NULL;
                     root->right=ptr;
                }
                else
                   insert(root->right,data);
          }
                     
     }    
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
/* Code to check whether tree is balanced or not*/
int balancing(struct tree* root){

   if(root==NULL)
        return 1;
   else{
       int balfact;
       int left=maxDepth(root->left);
       int right=maxDepth(root->right);
       if(left<=right) 
         balfact=right-left;
       else
         balfact=left-right;
       if(balfact<2)
       {
           return 1;
       }
       else
           return -1;
   }
}

int balanced(struct tree* root){
    static int sum; 

    if(root==NULL)
          return 0;

    else{
      sum+=balancing(root);
      balanced(root->left);
      balanced(root->right); 
    }
   return sum;
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
  struct tree *root=NULL;
  struct tree *ptr;
  int n,data,i;
  cout<<"Enter no. of elements in a Binary Search Tree=\n";
  cin>>n;
  root=(struct tree *)malloc(sizeof(struct tree));
  cin>>root->data;
  root->left=root->right=NULL;
  for(i=1;i<n;i++){ 
     cin>>data;
     insert(root,data);
  }  

  cout<<"\n";
  print(root,n);
  
  if(balanced(root)==n)
    cout<<"\nTree is height balanced";

  else
    cout<<"\nTree is not height balanced";
  return 0;
}

  
  
  
  
  







