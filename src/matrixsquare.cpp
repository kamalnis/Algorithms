#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int maxSquare(vector<vector<int> > myvec,int m,int n){

    if(m==1 || n==1){
        return 0;
    }

    vector<vector<int> > newvec(m-1,vector<int> (n-1,0));
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            newvec[i][j]=myvec[i][j]+myvec[i+1][j]+myvec[i][j+1]+myvec[i+1][j+1];
        }
    }
    //Preprocessing
    bool is_square_matrix_present=false;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            if(newvec[i][j]!=4){
                newvec[i][j]=0;
            }
            else{
                is_square_matrix_present=true;
                newvec[i][j]=1;
            }
        }
    }
    return (is_square_matrix_present+maxSquare(newvec,m-1,n-1));
}

int main(){
    int m,n;
    cout<<"Enter the number of rows and column=";
    cin>>m>>n;

    vector<vector<int> > myvec(m,vector<int> (n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>myvec[i][j];
        }
    }
    cout<<"\nMax square = "<<pow((maxSquare(myvec,m,n)+1),2)<<endl;

}