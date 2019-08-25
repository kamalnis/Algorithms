#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>

using namespace std;

struct node{
  char ch;
  int frequency;
  struct node *left,*right;

};

vector<int> myvec;
//set<char,vector<int> > encoder;
int encoder[26];

bool cmp(struct node *i,struct node *j){
     return (i->frequency > j->frequency);

}



int huffman_code(struct node *root){

     if(root->left==NULL && root->right==NULL){
        cout<<root->ch<<"          ";
        for(vector<int>::iterator it=myvec.begin();it!=myvec.end();it++){
            cout<<*it; 
            encoder[root->ch - 'a']= encoder[root->ch - 'a']*10+ *it;
        }
        
        cout<<endl; 
        return 0;
     } 

     if(root->left!=NULL){
          myvec.push_back(0);
          huffman_code(root->left);
          myvec.pop_back(); 
     }  
     if(root->right!=NULL){
          myvec.push_back(1); 
          huffman_code(root->right);
          myvec.pop_back();
     }
     return 0; 
}

int main(){
   int n;
   struct node *root;
   cout<<"\nEnter the number of elements in an array=";
   cin>>n;
   
   for(int i=0;i<26;i++)
       encoder[i]=0; 
   //struct node arr[n];
   vector<struct node*> vec;
   for(int i=0;i<n;i++){
      struct node *temp=(struct node*)malloc(sizeof(struct node));
      cin>>temp->ch;
      cin>>temp->frequency;
      temp->left=NULL;
      temp->right=NULL;
      vec.push_back(temp);
   }
   make_heap(vec.begin(),vec.end(),cmp);
   //sort(vec.begin(),vec.end(),cmp);
   
  /*for(int i=0;i<n;i++){
       cout<<vec[i].ch<<endl;
   }*/ 
   for(int i=0;i<n-1;i++){
       pop_heap(vec.begin(),vec.end(),cmp);
       struct node *temp=vec.back();
       vec.pop_back(); 
       pop_heap(vec.begin(),vec.end(),cmp);
       struct node *temp1=vec.back();
       vec.pop_back();
       struct node *temp3=(struct node*)malloc(sizeof(struct node));
       temp3->ch='-';
       temp3->frequency=temp->frequency+temp1->frequency;
       if(temp1->frequency < temp->frequency){
             temp3->left=temp1;
             temp3->right=temp;
       }          
       else{

             temp3->left=temp;
             temp3->right=temp1;
       }
     //  cout<<"n";	
       vec.push_back(temp3);
       push_heap(vec.begin(),vec.end(),cmp);
      
   } 
   //cout<<"end"; 
   cout<<"Character Code\n"; 
   huffman_code(*vec.begin());

   char str[100];
   cout<<"\nEnter your message=";
   cin>>str;
   cout<<"\nEncoded message=";
   for(int i=0;i<strlen(str);i++){
        cout<<encoder[str[i]-'a']<<" ";
   
   } 
}

