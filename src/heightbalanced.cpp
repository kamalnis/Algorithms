#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

struct tree{
   char data;
   struct tree *left;
   struct tree *right;
};

int mirror(struct tree* node)
{
   if(node==NULL)
      return 0;
   else{
    struct tree *temp=node->left;
    node->left=node->right;
    node->right=temp;
    mirror(node->left);
    mirror(node->right);
  }
 return 0;
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
     
/* Print nodes at a given level */
void printGivenLevel(struct tree* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int print(struct tree* ptr,int n)
{   
       int i;
       for(i=1;i<=n;i++)
       {
          printGivenLevel(ptr, i);
          cout<<endl;
       }
     return 0;
}



int main()
{
  struct tree *root=NULL,*ptr;
  int n,l,n1,i;
  char arr[100];
  cout<"Enter - for null and alphabet as data\n";
  cout<<"Number of levels of binary tree=";
  cin>>l;
  cout<<"\nEnter the tree levelwise:-\n";
  n=pow(2,l)-1;
  n1=pow(2,l-1)-1;
  struct tree * temp[n];
  for(i=0;i<n;i++){ 
      struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
      cin>>ptr->data;
      ptr->left=ptr->right=NULL;
      if(root== NULL){
          if(ptr->data=='-')
              ptr=root=NULL;
             
          else{   
             root=ptr;
             temp[i]=root;
          }
      }
      else{
         if(ptr->data=='-')
           temp[i]=NULL;
         else
           temp[i]=ptr;
      } 
  }  
  for(i=1;i<=n1;i++){
      if(temp[i-1]!=NULL){
             temp[i-1]->left=temp[2*i-1];
             temp[i-1]->right=temp[2*i];
      }
  }
  cout<<"\n";
  print(root,l);
  if(balanced(root)==1)
    cout<<"\nTree is height balanced";

  else
    cout<<"\nTree is not height balanced";
  return 0;
}

  
  
  
  
  







