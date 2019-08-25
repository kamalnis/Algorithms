#include<iostream>
#include<utility>   
#include<vector>
#include<algorithm>
using namespace std;
bool mycompare(pair<int,int> &a, pair<int,int> &b){
    return a.first<b.first;
}

void mergeInterval(vector<pair<int,int> > &Intervals){
    int n = Intervals.size();
    sort(Intervals.begin(), Intervals.end(),mycompare);
    int prev = 0;
    for(int i=1;i<n;i++){
        if(Intervals[prev].second >= Intervals[i].first){
            Intervals[prev].second = max(Intervals[prev].second,Intervals[i].second);
        }
        else{
            prev++;
            Intervals[prev]=Intervals[i];
        }

    }

    for(int i = Intervals.size()-1; i>prev;i--){
        Intervals.erase(Intervals.begin()+i);
    }
}

void printIntervals(vector<pair<int,int> > Intervals){
    for(int i=0;i<Intervals.size();i++){
        cout<<Intervals[i].first<<" "<<Intervals[i].second<<endl;
    }
}

int main(){
    vector<pair<int,int> > Intervals;
    Intervals.push_back(make_pair(1,2));
    Intervals.push_back(make_pair(3,5));
    Intervals.push_back(make_pair(6,7));
    Intervals.push_back(make_pair(8,10));
    Intervals.push_back(make_pair(12,16));
    Intervals.push_back(make_pair(4,9));



    mergeInterval(Intervals);
    cout<<"\nIntervals are as follows:\n";
    printIntervals(Intervals);
}