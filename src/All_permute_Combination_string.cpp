#include<iostream>
#include<cstring>

using namespace std;


void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 

void permute(char *arr, int l, int r)
{
   int i;
   if (l == r)
        printf("%s\n", arr);
   else
   {
       for (i = l; i <= r; i++)
       {
       	  //strncpy(a+l,a+i,r-l) 
          swap((arr+l), (arr+i));
          permute(arr, l+1, r);
          swap((arr+l), (arr+i)); 
          
       }
   }
}

int main(){
   char str[100];
   cout<<"\nEnter a string=";
   cin>>str;	
   int n=strlen(str);
   
   cout<<"\n All combination of the string is as follows:-";
   
   for(int i=0;i< 1<<n;i++){
   	  for(int j=0;j<n;j++){
   	     if(i & 1<<j)
			cout<<str[j];		
   	  	
   	  }
   	  cout<<endl;
   	
   }

   cout<<"\n All permutations of the string is as follows:-"; 	
   permute(str, 0, n-1);

	
}
