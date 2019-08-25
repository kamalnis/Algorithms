/*
   WAP to implement Polynomial and overload the operations in C++.
   Programmer-> Nishant Kamal
   Date-> 8/16/2015

*/
#include<iostream>
#include<cstdio>
using namespace std;

class Polynomial{
	public: double coef;
	        int exp;
            Polynomial *next;
            /*Overloaded Constructor 1*/
            Polynomial(double c,int e){
            	this->coef=c;
            	this->exp=e;
            	this->next=NULL;
            }
            /*Overloaded Constructor 2*/
            Polynomial(){
            	coef=0.0;
            	exp=0;
            	next=NULL;
            }
            /*ADDITION*/
            Polynomial operator+(Polynomial *b){
            	Polynomial *temp=this,*head=NULL,*ptr=NULL,*ptr1=NULL;
            	while(temp!=NULL && b!=NULL){
            		ptr=new Polynomial();
            		if(temp->exp==b->exp){
            			ptr->coef=temp->coef + b->coef;
            			ptr->exp=temp->exp;
           			    temp=temp->next;
            			b=b->next;
            		}
            		else if(temp->exp < b->exp){
            			ptr->coef=b->coef;
            			ptr->exp=b->exp;
            			b=b->next;
            		}
            		else{
            			ptr->coef=temp->coef;
            			ptr->exp=temp->exp;
            			temp=temp->next;
            		}
            		if(head==NULL){
            			     head=ptr;
            			     ptr1=ptr;
            		}
            		else{
            			if(ptr->coef != 0.0){
            			     ptr1->next=ptr;
            			     ptr1=ptr;
            			}
            		}
            	}
            	return *head;
            }
            /*SUBTRACTION*/
            Polynomial operator-(Polynomial *b){
            	Polynomial *temp=this,*head=NULL,*ptr=NULL,*ptr1=NULL;
            	while(temp!=NULL && b!=NULL){
            		ptr=new Polynomial();
            		if(temp->exp==b->exp){
            			ptr->coef=temp->coef - b->coef;
            			ptr->exp=temp->exp;
           			    temp=temp->next;
            			b=b->next;
            		}
            		else if(temp->exp < b->exp){
            			ptr->coef=-b->coef;
            			ptr->exp=b->exp;
            			b=b->next;
            		}
            		else{
            			ptr->coef=temp->coef;
            			ptr->exp=temp->exp;
            			temp=temp->next;
            		}
            		if(head==NULL){
            			    head=ptr;
            			    ptr1=ptr;
            		}
            		else{
            			if(ptr->coef != 0.0){
						    ptr1->next=ptr;
  			                ptr1=ptr;
	                    }
            		}
            	}
            	return *head;
            }
            /* MULTIPLICATION*/
            Polynomial operator*(Polynomial *b){
            	Polynomial *temp=this,*head=NULL,*ptr=NULL,*ptr1=NULL,*ptr2=NULL,*ptr3=NULL;
                while(temp!=NULL){
                	ptr2=temp;
                	ptr1=b;
                	while(ptr1!=NULL){
                		ptr=new Polynomial();
					    ptr->coef=temp->coef * ptr1->coef;
						ptr->exp= temp->exp + ptr1->exp;
						if(head==NULL){
						       head=ptr;
							   ptr3=ptr;
						}
						else{
							ptr3->next=ptr;
							ptr3=ptr;
						}
						ptr1=ptr1->next;
                	}
                	temp=temp->next;
                }
                Sort(head);
                RemoveDuplicate(head);
                return *head;
            }
			/*SORTING*/
			void Sort(Polynomial *head){
				Polynomial *ptr=NULL,*ptr1=NULL,*temp=NULL;
				int max,x;
				double x1;
				ptr=head;
				while(ptr!=NULL){
					ptr1=ptr->next;
					max=ptr->exp;
					temp=NULL;
					while(ptr1!=NULL){
						if(ptr1->exp > max){
						       max=ptr1->exp;
							   temp=ptr1;
						}
						ptr1=ptr1->next;
					}
					if(temp!=NULL){
					     x1=ptr->coef;
					     ptr->coef=temp->coef;
					     temp->coef=x1;
					     x=ptr->exp;
					     ptr->exp=temp->exp;
					     temp->exp=x;
					}
					ptr=ptr->next;
				}
			}
			/*Remove Duplicate exponent and add coeficient*/
			void RemoveDuplicate(Polynomial *head){
			       Polynomial *ptr=head,*ptr1=NULL,*ptr2=NULL;
			       int e;
		           double c;
			       while(ptr!=NULL){
			       	       ptr1=ptr->next;
			       	       ptr2=ptr;
			       	       while(ptr1!=NULL){
			       	       	     if(ptr1->exp == ptr->exp){
			       	       	     	ptr->coef+=ptr1->coef;
			       	       	     	ptr2->next=ptr1->next;
			       	       	     	ptr1->next=NULL;
			       	       	     	ptr1=ptr2->next;
			       	       	     }
			       	       	     else{
			       	       	     	ptr2=ptr1;
			       	       	     	ptr1=ptr1->next;
			       	       	     }
			       	       }
			       	       ptr=ptr->next;
			       }
			}
               /* DISPLAY */
               void static display(Polynomial *ptr){
                      	cout<<endl;

	              if(ptr->coef!=0.0)
	                       printf("%.3lfx^%d",ptr->coef,ptr->exp); //Displaying first element of the polynomial
      
	              else
	                       printf("0"); 
	  
	               ptr=ptr->next;  
	               while(ptr->next!=NULL){
	                        printf(" %+.3lfx^%d",ptr->coef,ptr->exp);
		                ptr=ptr->next;
	               }
	               if(ptr->exp!=0)
	                   printf(" %+.3lfx^%d",ptr->coef,ptr->exp); //Displaying last element of the polynomial      
	               else
	                   printf(" %+.3lf",ptr->coef);
                         
               }
               /*    //Assignment operator overloaded 
                   void operator=(Polynomial &b){
                                 Polynomial *head=NULL,*ptr=NULL,*ptr1=NULL;*temp=this;
                                 ptr=&b;
                                 
                                 while(ptr!=NULL){
                                            temp=new Polynomial();
                                            temp->coef=ptr->coef;
                                            temp->exp=ptr->exp;
                                            if(head==NULL){
                                                 head=temp;
                                                 this=temp;
                                                 ptr1=temp;
                                            }
                                            else{
                                                 ptr1->next=temp; 
                                                 ptr1=temp;
                                            }
                                            ptr=ptr->next;
                                  }    
                                   
                   }*/
                // += overator overloaded

                void operator+=(Polynomial *b){
                        *this=this->operator+(b);
                }
 
                void operator-=(Polynomial *b){
                        *this=(*this) - b;
                }
                void operator*=(Polynomial *b){
                        *this=(*this) * b;
                }                  	        	       	
};

int main(){
    double c;
    int e=1,x;
	Polynomial *head1=NULL,*poly2=NULL,*ptr=NULL,*ptr1=NULL,poly1,poly3;
	cout<<"Enter first polynomial=";
	ptr=new Polynomial(0.0,1);
	while(e!=0){
		scanf("%lfx%d",&c,&e);
		ptr= new Polynomial(c,e);
		if(head1==NULL){
		    head1=ptr;
			ptr1=ptr;
		}
		else{
			ptr1->next=ptr;
			ptr1=ptr;
		}
	}
	poly1=*head1;    // converting it for simpler use of polynomial and leaving polynomial 2 as pointer
    cout<<"\nEnter second polynomial=";
	ptr=new Polynomial(0.0,1);
	e=1;
	while(e!=0){
		scanf("%lfx%d",&c,&e);
		ptr= new Polynomial(c,e);
		if(poly2==NULL){
			poly2=ptr;
			ptr1=ptr;
		}
		else{
			ptr1->next=ptr;
			ptr1=ptr;
		}
	}
    cout<<"\nEnter:-\n 1->Addition\n 2->Subtraction\n 3->Multiplication\n 4-> Assignment(=) operator\n 5-> += operator\n 6-> -= operator\n 7-> *= operator\n ";
    cout<<"Enter your choice=";
    cin>>x;
    switch(x){
    	case 1: poly3=poly1 + poly2;
                Polynomial::display(&poly3); 
    	        break;
        case 2: poly3=poly1 - poly2;
                Polynomial::display(&poly3); 
                break;
        case 3: poly3=poly1 * poly2;
                Polynomial::display(&poly3); 
                break;
        case 4: poly3=poly1;
                Polynomial::display(&poly3);  
                break;
        case 5: poly1+=poly2;
                Polynomial::display(&poly1); 
                break;
        case 6: poly1-=poly2;
                Polynomial::display(&poly1); 
                break;
        case 7: poly1*=poly2;
                Polynomial::display(&poly1); 
                break;       
        
        default: break;
    } 
	return 0;  
}
		               
            
	        
	
