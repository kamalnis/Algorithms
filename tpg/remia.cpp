#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
  public:
    int value;
    Node *left;
    Node *right;
};

vector<Node> leaf;
vector<Node> F;
vector<int> num;

int power_of_two(int value){

   while(value!=1){
      if(value%2!=0)
           return 1;
      value/=2;
   }
   return 0;

}

int interpolation(Node *node){

   while(power_of_two(node->value)!=0){
        Node *left=new Node;
        Node *right=new Node;
       left->left=right->left=left->right=right->right=NULL;
       int power = 1;
       while(power < node->value)
          power*=2;

       num.push_back(power);
       left->value=power;
       right->value=2*node->value-power;
       node->left=left;
       node->right=right;
       leaf.push_back(*left);
       cout<< left->value<<endl;
       node=right;
   }
   num.push_back(node->value);
   leaf.push_back(*node);
   cout<< node->value<<endl;
}

bool cmp(const Node a,const Node b){
    return a.value > b.value;
}


int build_edt_forest(){

   make_heap(leaf.begin(),leaf.end(),cmp);
   while(!leaf.empty()){
        //cout<<"nishant";
        pop_heap(leaf.begin(),leaf.end(),cmp);
        Node x=leaf.back();
        cout<< x.value<<endl;
        leaf.pop_back();
        if(x.value!=1024){
           Node *z=new Node;
           z->right=NULL;
           z->value=x.value*2;
           z->left=&x;

           pop_heap(leaf.begin(),leaf.end(),cmp);
           Node y=leaf.back();
           leaf.pop_back();

           if(x.value==y.value)
              z->right=&y;

           else{
               leaf.push_back(y);
               push_heap(leaf.begin(),leaf.end(),cmp);
           }
           leaf.push_back(*z);
           push_heap(leaf.begin(),leaf.end(),cmp);
        }
        else{
           F.push_back(x);
        }
   }

}


int main(){
  int conc;
  cout<<"\nEnter the concentration of sample needed=";
  cin>>conc;
  Node *start=new Node;
  start->value=conc;
  start->left=NULL;
  start->right=NULL;
  interpolation(start);

  cout<<"\nExponential build roots=\n";

  build_edt_forest();
  for(vector<Node>::iterator it=F.begin();it!=F.end();it++){
    cout<< it->value<<endl;
  }
}
