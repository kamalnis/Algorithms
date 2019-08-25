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

void levelOrderCreation(struct tree *root,int level){
   if(root==NULL)
       return;
   if(level==1){
          struct tree *ptr=(struct tree*)malloc(sizeof(struct tree));
          cin>>ptr->data;
          ptr->left=ptr->right=NULL;
          if(ptr->data!='-')
             root->left=ptr;
          else free(ptr);
 
          ptr=(struct tree*)malloc(sizeof(struct tree));
          cin>>ptr->data;
          ptr->left=ptr->right=NULL;
          if(ptr->data!='-')
            root->right=ptr;
          else free(ptr);

   }
   else if(level>1){
        levelOrderCreation(root->left,level-1);
        levelOrderCreation(root->right,level-1);
   }
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
  root=(struct tree*)malloc(sizeof(struct tree));
  cin>>root->data;
  root->left=root->right=NULL;
  
  for(i=2;i<=l;i++)
      levelOrderCreation(root,i-1);    
     

  cout<<"\n";
  print(root,l);
  mirror(root);
  cout<<"\n";
  print(root,l);
  return 0;
}

  
  
  
  
  

