#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data){
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *constructTreeUtil(int pre[], int low, int high, int size){
    if(low>high){
        return NULL;
    }

    int i;
    for(i=low;i<=high;i++){
        if(pre[i]>pre[low]){
            break;
        }
    }
    node *root = newNode(pre[low]);
    root->left = constructTreeUtil(pre,low+1,i-1,size);
    root->right = constructTreeUtil(pre,i,high,size);
    return root;

}

node *constructTreeUtil_1(int pre[],int &preindex, int key, int minm, int maxm, int size){
    if(preindex>=size){
        return NULL;
    }
    node *root = NULL;
    if(key>minm && key<maxm){
        root = newNode(key);
        preindex +=1;

        if(preindex < size){
            root->left = constructTreeUtil_1(pre,preindex,pre[preindex],minm,key,size);
            root->right = constructTreeUtil_1(pre,preindex,pre[preindex],key,maxm,size);
        }

    }
    return root;
}

node *constructTree(int pre[], int size){
    int preindex = 0;
    //return constructTreeUtil(pre, 0, size-1, size);
    return constructTreeUtil_1(pre, preindex,pre[0], INT_MIN, INT_MAX, size);

}

void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

int main(){
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre)/sizeof(pre[0]);

    node *root = constructTree(pre, size);
    inorder(root);
    return 0;

}