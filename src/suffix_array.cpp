#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct suffix{
	int index;
	int rank[2];
};


int cmp(suffix a,suffix b){
	return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1: 0):(a.rank[0]<b.rank[0]?1: 0);
}


void compute_suffix(string T,int s[]){
	int n=T.length();
	suffix suffixes[n];
	int rank[n];

	for(int i=0;i<n;i++){
		suffixes[i].index=i;
		rank[i]=T[i]-'a';
	}	
		

	for(int k=1;k<n;k*=2){
		for(int i=0;i<n;i++){
			suffixes[i].rank[0]=rank[suffixes[i].index];
			suffixes[i].rank[1]=suffixes[i].index+k<n?rank[suffixes[i].index+k]:-1;
		}
	
		sort(suffixes,suffixes+n,cmp);
		rank[suffixes[0].index]=0;

		for(int i=1;i<n;i++){
			rank[suffixes[i].index]=((suffixes[i].rank[0]==suffixes[i-1].rank[0])&&(suffixes[i].rank[1]==suffixes[i-1].rank[1]))?rank[suffixes[i-1].index]:rank[suffixes[i-1].index]+1;
		}

	}
			
	for(int i=0;i<n;i++)
		s[i]=suffixes[i].index;
			
}

void suffix_matching(string T,string P){
	int n=T.length();
	int m=P.length();

	int s[n];

	compute_suffix(T,s);

	int low=0,high=n-1;
	int lb=low,ub=low-1;

	while(low<=high){
		int mid=(low+high)/2;
		int res;
		if((res=T.compare(s[mid],m,P))==0){
			lb=mid;
		}

		if(res>=0)
			high=mid-1;
			
		else
			low=mid+1;
	}
	low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		int res;
		if((res=T.compare(s[mid],m,P))==0){
			ub=mid;
		}

		if(res>0)
			high=mid-1;
			
		else
			low=mid+1;
	}

	for(int i=lb;i<=ub;i++)
		cout<<"pattern found at "<<s[i]<<endl;
}
			

int main(){
	 string txt="AABAACAADAABAAABAA";
     string pat="AABA";

	//string txt="AABAACAADAABAAABAA";
	//string pat="acacabacacabacacac";
	//string txt="this is a test text";
	//string pat="Test";
	suffix_matching(txt,pat);
	return 0;
}

