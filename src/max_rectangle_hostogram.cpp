#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int maxAreaHistogram(vector<int> histogram){
    stack<int> mystack;
    int maxArea = 0;
    int area;
    mystack.push(0);
    int i=0;
    while(i<histogram.size()){
        if(mystack.empty() || histogram[mystack.top()]<=histogram[i]){
            mystack.push(i++);
        }
        else{
            int tp = mystack.top();
            mystack.pop();
            area = histogram[tp]*(mystack.empty()?i:i-mystack.top()-1);
            maxArea = max(area, maxArea);
        }
    }
    while(!mystack.empty()){
        int tp = mystack.top();
        mystack.pop();
        area = histogram[tp]*(mystack.empty()?i:i-mystack.top()-1);
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
int main(){
    int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    vector<int> histogram;
    histogram.push_back(6);
    histogram.push_back(2);
    histogram.push_back(5);
    histogram.push_back(4);
    histogram.push_back(5);
    histogram.push_back(1);
    histogram.push_back(6);
    cout<<maxAreaHistogram(histogram)<<endl;
}

