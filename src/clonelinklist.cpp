#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct node{
	int d;
	struct node *next,*random;
};
struct node *head=NULL;


void createNode(int d,int i,node* arr[])
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->d=d;
	temp->next=NULL;
	arr[i]=temp;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node *tt=head;
		while(tt->next!=NULL)
		{
			tt=tt->next;
		}
		tt->next=temp;
	}
	
}

int main()
{
	int n,d,j=0;
	cout<<"Enter number of nodes :";
	cin>>n;
	node* arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value :";
	    cin>>d;
      	createNode(d,i,arr);
	}
	struct node *tt;
	
	srand(time(NULL));
	tt=head;

	for(int i=0;i<n;i++)
	{
		tt->random=arr[rand()%n];
		tt=tt->next;
		
		
	}
	
	
	tt=head;
	struct node *nn,*copy,*copy1;
	while(tt!=NULL)
	{
		nn=tt->next;
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		
		newnode->d=tt->d;
		newnode->next=tt->next;
		tt->next=newnode;
		
		tt=nn;
		
	}
	tt=head;
	copy=head->next;
	copy1=head->next;
	while(tt!=NULL)
    {
    	tt->next->random = tt->random->next;
    	tt=tt->next->next;
	}
	tt=head;
	while(tt->next->next!=NULL)
	{
		tt->next=tt->next->next;
		tt=tt->next;
		copy->next=copy->next->next;
		copy=copy->next;
	}
	tt->next=NULL;
	tt=copy1;
	while(tt!=NULL)
	{
		cout<<tt->d<<" ";
		tt=tt->next;
		
	}
	return 0;
}
