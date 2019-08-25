#include<iostream>
#include<vector>
using namespace std;

struct building{
int left;
int height;
int right;
};

struct skyline{
	int left;
	int height;
	skyline(int l,int h){
		left=l;
		height=h;
	}
};


vector<skyline> merge(vector<skyline>res1,vector<skyline>res2){
	vector<skyline>res;
	vector<skyline>::iterator it1=res1.begin();
	vector<skyline>::iterator it2=res2.begin();
	int h1=0;
	int h2=0;
	while(it1!=res1.end() && it2!=res2.end()){
		if(it1->left<=it2->left){
			h1=it1->height;
			int h=max(h1,h2);
			if(res.size()>0 && it1->left==(res[res.size()-1].left))
				res[res.size()-1].height=max(h,res[res.size()-1].height);

			else if(res.size()==0 || h!=(res[res.size()-1].height))
				res.push_back(*(new skyline(it1->left,h)));
			it1++;
 		}
		else{
			h2=it2->height;
			int h=max(h1,h2);
			if(res.size()>0 && it2->left==(res[res.size()-1].left))
				res[res.size()-1].height=max(h,res[res.size()-1].height);
			else if(res.size()==0 || h!=(res[res.size()-1].height))
			res.push_back(*(new skyline(it2->left,h)));
			it2++;
		}
	}

	while(it1!=res1.end()){
		res.push_back(*it1);
		it1++;
	}

	while(it2!=res2.end()){
		res.push_back(*it2);
		it2++;
	}
	return res;




}

vector<skyline> findskyline(building arr[],int l,int r){
	if(l==r){
		vector<skyline> res;
        res.push_back(*(new skyline(arr[l].left,arr[l].height)));
        res.push_back(*(new skyline(arr[l].right,0)));
        return res;
    }

		vector<skyline> res;
		vector<skyline> res1;
		vector<skyline> res2;
		int mid=(l+r)/2;
		res1=findskyline(arr,l,mid);
		res2=findskyline(arr,mid+1,r);
		res=merge(res1,res2);
		return res;

}



	
int main(){
	//building arr[]={{1, 11, 5}, {2, 6, 7}, {3, 13, 9}, {12, 7, 16}, {14, 3, 25}, {19, 18, 22}, {23, 13, 29}, {24, 4, 28}};
	building arr[]={{1, 11, 2}, {2, 6, 7}, {3, 13, 9}, {12, 7, 16}, {14, 3, 25}, {19, 18, 22}, {23, 13, 29}, {24, 4, 28}};

	//building arr[]={{1, 11, 5}, {2, 6, 7}};
    int n = sizeof(arr)/sizeof(arr[0]);
	vector<skyline> res;
	res=findskyline(arr,0,n-1);
	for(vector<skyline>::iterator it=res.begin();it!=res.end();it++)
		cout<<it->left<<','<<it->height<<endl;

	return 0;

}
