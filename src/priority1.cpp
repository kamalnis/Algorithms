#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
  int data;
  int priority;
  struct node *left;
  struct node *right;
  struct node *parent;
};

int flag=0;
struct node *last_node=NULL,*last_node_delete=NULL;

/* Depth Calculation */
int minDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       int ld = minDepth(node->left);
       int rd = minDepth(node->right);
 

       if (ld < rd)
           return(ld+1);
       else 
           return(rd+1);
   }
} 

int maxDepth(struct node* node)
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

/*Insertion Code*/
void compare_update(struct node *ptr){

      struct node *temp=ptr->parent;
      int temp1;
      while(temp!=NULL){
           if(temp->priority < ptr->priority){
                temp1=temp->priority;
                temp->priority=ptr->priority;
                ptr->priority=temp1;

                temp1=temp->data;
                temp->data=ptr->data;
                ptr->data=temp1;
           }
           temp=temp->parent;
           ptr=ptr->parent; 
              
      }

}

void insert(struct node *root,int priority,int data,int level){
   if(root==NULL && level==0)
     return ;

   if(root->left==NULL && level==1 && flag==0){
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->priority=priority;
        ptr->right=ptr->left=NULL;
        ptr->parent=root;
        root->left=ptr;
        flag=1;
        compare_update(root->left);
        
   }
   else if(root->right==NULL && level==1 && flag==0){
        struct node *ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->priority=priority;
        ptr->parent=root;
        ptr->right=ptr->left=NULL;
        root->right=ptr;
        flag=1;
        compare_update(root->right); 
   }


   if(level>1){
        insert(root->left,priority,data,level-1);

        insert(root->right,priority,data,level-1);
   }
}

/* Deletion code */
void heapify(struct node* root){

    if(root->right==NULL)
           return;

    else if(root->left==NULL)
          return;

    if(root->priority > root->left->priority && root->priority > root->right->priority)
               return; 

    if(root->left->priority > root->priority && root->left->priority > root->right->priority){
           struct node *ptr=root->left;
           int temp;

           temp=root->data;
           root->data=ptr->data;
           ptr->data=temp;

           temp=root->priority;
           root->priority=ptr->priority;
           ptr->priority=temp;

           heapify(ptr);

    }
    else if(root->priority < root->right->priority){
           struct node *ptr=root->right;
           int temp;

           temp=root->data;
           root->data=ptr->data;
           ptr->data=temp;

           temp=root->priority;
           root->priority=ptr->priority;
           ptr->priority=temp;

           heapify(ptr);

    }

}

/* For finding last node in last level */
void findLastNode(struct node *root,int level){

     if(root==NULL)
           return;

     else if(level==1 && flag==0){
             if(root==NULL)
                   flag=1;
             else last_node=root;
     }
     if(level>1){
         findLastNode(root->left,level-1);
         findLastNode(root->right,level-1); 
     }   
 
}

int delete_node(struct node* root){
     flag=0;
     int level=maxDepth(root);
     findLastNode(root,level);
     struct node *ptr=NULL;
     int temp,data;
   
    // cout<<"\nLast node data "<<last_node->data<<endl;
     data=root->data;
     temp=root->data;
     root->data=last_node->data;
     last_node->data=temp;

     temp=root->priority;
     root->priority=last_node->priority;
     last_node->priority=temp;

     ptr=last_node->parent;
     if(ptr!=NULL){
         if(ptr->right==last_node)
            ptr->right=NULL;

         else 
            ptr->left=NULL;
         
         heapify(root);
     }
     else{
        last_node_delete=NULL; 
     }
     last_node=NULL;

     

     return data;  
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout<<root->data<<" ";

    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int print(struct node* ptr,int n)
{   
       int i;
       for(i=1;i<=n;i++)
       {
          printGivenLevel(ptr, i);
          cout<<endl;
       }
     return 0;
}


int main(){

    int n,i,data,pr,level,x;
    struct node *root=NULL;
    
    //cout<<"\nEnter the no of elements in Priority queue=";
    //cin>>n;


   /* for(i=1;i<n;i++){
           cin>>data>>pr;
           flag=0;
           level=minDepth(root);  
           insert(root,pr,data,level);
    }*/
   /* cout<<"\n Priority queue is as follows:-\n";
    level=maxDepth(root);
    print(root,level);*/

   /* data=delete_node(root);
    cout<<"\n Deleted data="<<data<<"\n\n";
    cout<<"\n Priority queue is as follows:-\n";
    level=maxDepth(root);
    print(root,level);*/
    

   while(1){
    cout<<"\n\nEnter:-\n1 -> Insert\n2 -> Delete\n 3 -> Print\n 4 -> Exit\n";
    cout<<"\nEnter your choice=";
    cin >> x; 
    switch(x){

       case 1: if(root==NULL){
                      root=(struct node *)malloc(sizeof(struct node));
                      cout<<"\nEnter elements and there priority:-\n";

                      cin>> root->data >> root->priority;
                      root->left=root->right=root->parent=NULL; 
                      last_node_delete=root;
               }
               else{
                      cout<<"\nEnter elements and there priority:-\n";  
                      cin>>data>>pr;
                      flag=0;
                      level=minDepth(root);  
                      insert(root,pr,data,level);
               }
               cout<<"\n Priority queue is as follows:-\n";
               level=maxDepth(root);
               print(root,level); 
          
               break;
 
       case 2: if(last_node_delete==NULL){
                   cout<<"\nNo element in the priority queue to delete.";
                   root=NULL;
               }  
     
               else{
                   data=delete_node(root);
                   cout<<"\n Deleted data="<<data<<"\n\n";
                   cout<<"\n Priority queue is as follows:-\n";
                   level=maxDepth(root);
                   print(root,level);
               }
               break;

       case 3: cout<<"\n Priority queue is as follows:-\n";
               level=maxDepth(root);
               print(root,level);
 
               break;

      case 4: exit(0);
              break;

      default: exit(0);
               break;

    } 
   }
   return 0;
}
