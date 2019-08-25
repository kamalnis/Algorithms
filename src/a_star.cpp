#include<iostream>
#include<pair>
#include<stack>

#define ROW 9;
#define COL 10;
typedef pair<int,int> Pair;
typedef pair<double,pair<int,int> > pPair;
using namespace std;


struct cell{
  int parent_i,parent_j;
  double f,g,h;

};

bool isValid(int row,int col){
   return (row>=0) && (row<ROW) && (col>=0) && (col<COL);
}

bool isUnblocked(int grid[][COL],int row,int col){
     if(grid[row][col]==1)
	   return true;
	 else
	    return false;
}

bool isDestination(int row,int col,Pair dest){
   if(row== dest.first && col==dest.second)
      return true;
	  
   else 
      return false;

}

double calculateHeuristic(int row, int col,Pair dest){
    return (double)sqrt((row-dest.first)*(row-dest.first)+(col-dest.second)*(col-dest.second));
}

void tracePath(cell cellDetails[][COL],Pair dest){
     int row=dest.first;
	 int col=dest.second;
	 stack<Pair> Path;
	 
	 while(!((row==cellDetails[row][col].parent_i) &&(col==cellDetails[row][col].parent_j))){
	       Path.push(make_pair(row,col));
		   int tempi=cellDetails[row][col].parent_i;
		   int tempj=cellDetails[row][col].parent_j;
	       row=tempi;
	       col=temp_j;
	 }
     Path.push(make_pair(row,col));
	 while(!Path.empty()){
	    Pair path_pair=Path.top();
		Path.pop();
		cout<<path_pair.first<<","<<path_pair.second<<endl;
	 
	 }
     return;

}

void aStar(int grid[][COL],Pair src,Pair dest){
   if(isValid(src.first,src.second)==false)
      return;
	  
   if(isValid(dest.first,dest.second)== false){
      return;
   }
   
   if(isUnblocked(grid,src.first,src.second)== false || isUnblocked(grid,dest.first,dest.second)){
       cout<<"Source or destination is blocked"<<endl;
	   return;
   }
   if(isDestination(src.first,src.second,dest){
       cout<<"We are already at the destination"<<endl;
	   return;
   
   }
   
   bool closedList[ROW][COL];
   memset(closedList,false,sizeof(closedList));
   
   cell cellDetails[ROW][COL];
   
   int i,j;
   
   for(i=0;i<ROW;i++){
	   for(j=0;j<COL;j++){
		   cellDetails[i][j].f=FLT_MAX;
		   cellDetails[i][j].g=FLT_MAX;
		   cellDetails[i][j].h=FLT_MAX;
		   cellDetails[i][j].parent_i=-1;
		   cellDetails[i][j].parent_j=-1;
	   }
   }
   
   i=src.first; j=src.second;
   
   cellDetails[i][j].f=0.0;
   cellDetails[i][j].g=0.0;
   cellDetails[i][j].h=0.0;
   cellDetails[i][j].parent_i=i;
   cellDetails[i][j].parent_j=j;
   
   set<pPair> openList;
   openList.insert(make_pair(0.0,make_pair(i,j)));
   
   bool foundDest=false;
   while(!openList.empty()){
	   pPair p=*openList.begin();
	   openList.erase(openList.begin());
	   i=p.second.first;
	   j=p.second.second;
	   closedList[i][j]=true;
	   
	   double fNew,gNew,hNew;
	   
	   if(isValid(i-i,j)==true){
		   if(isDestination(i-1,j,dest)== true){
			  cellDetails[i-1][j].parent_i=i;
              cellDetails[i-1][j].parent_j=j;
              cout<<"\nDestination cell is found"<<endl;
              tracePath(cellDetails,dest);
              foundDest=true;
              return;			 
		   }
	       else if(closedList[i-1][j] == false && isUnblocked(grid,i-1,j)){
		   
		      gNew=cellDetails[i][j].g +1.0;
		      hNew=calculateHeuristic(i-1,j,dest);
		      fNew=gNew+hNew;
		   
		      if(cellDetails[i-1][j].f==FLT_MAX || cellDetails[i-1][j].f<fNew){
				 openList.insert(make_pair(fNew,make_pair(i-1,j)));
			     cellDetails[i-1][j].f=fNew;
			     cellDetails[i-1][j].g=gNew;
			     cellDetails[i-1][j].h=hNew;
			     cellDetails[i-1][j].parent_i=i;
			     cellDetails[i-1][j].parent_j=j;
		      }		   
	       }
        }
		
		//2nd Successor
		
		if(isValid(i+1,j)==true){
			if(isDestination(i+1,j,dest)==true){
				cellDetails[i+1][j].parent_i=i;
				cellDetails[i+1][j].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
			}
			else if(closedList[i+1][j] == false && isUnblocked(grid,i-1,j)){
					gNew=cellDetails[i][j].g+1.0;
					hNew=calculateHeuristic(i+1,j,dest);
					fNew=gNew+hNew;
					
					if(cellDetails[i+1][j].f==FLT_MAX || cellDetails[i+1][j].f<fNew){
						openList.insert(make_pair(fnew,make_pair(i+1,j)));
						cellDetails[i+1][j].f=fNew;
						cellDetails[i+1][j].g=gNew;
						cellDetails[i+1][j].h=hNew;
						cellDetails[i+1][j].parent_i=i;
						cellDetails[i+1][j].parent_j=j;
					}
		    }		
		}
		
		//3rd Successor west
		if(isValid(i,j-1)==true){
			if(isDestination(i,j-1,dest)==true){
				cellDetails[i][j-1].parent_i=i;
				cellDetails[i][j-1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
			}
			else if(closedList[i][j-1]==false && isUnblocked(grid,i,j-1)){
				 gNew=cellDetails[i][j-1].g+1.0;
				 hNew=calculateHeuristic(i,j-1,dest);
				 fNew=gNew+hNew;
				 
				 if(cellDetails[i][j-1].f==FLT_MAX || cellDetails[i][j-1]<fNew){
					 openList.insert(make_pair(fNew,make_pair(i,j-1)));
					 cellDetails[i][j-1].f=fNew;
					 cellDetails[i][j-1].g=gNew;
					 cellDetails[i][j-1].h=hNew;
					 cellDetails[i][j-1].parent_i=i;
					 cellDetails[i][j-1].parent_j=j;
				 }
			}
		}
		
		//4th Successor East
		if(isValid(i,j+1) == true){
			if(isDestination(i,j+1,dest)==true){
				cellDetails[i][j+1].parent_i=i;
				cellDetails[i][j+1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
                return;				
			}
			else if(closedList[i][j+1]==false && isUnblocked(grid,i,j+1)){
				gNew=cellDetails[i][j+1].g+1.0;
				hNew=calculateHeuristic(i,j+1,dest);
				fNew=gNew+hNew;
				
				if(cellDetails[i][j+1].f==FLT_MAX || cellDetails[i][j+1]<fNew){
					openList.insert(make_pair(fNew,make_pair(i,j+1)));
					cellDetails[i][j+1].f=fNew;
					cellDetails[i][j+1].g=gNew;
					cellDetails[i][j+1].h=hNew;
					cellDetails[i][j+1].parent_i=i;
					cellDetails[i][j+1].parent_j=j;
				}
			}
		}
		//5th Successor NE
		if(isValid(i-1,j+1)==true){
			if(isDestination(i-1,j+1,dest)==true){
				cellDetails[i-1][j+1].parent_i=i;
				cellDetails[i-1][j+1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
				
			}
			else if(closedList[i-1][j+1]==false && isUnblocked(grid,i-1,j+1)){
				gNew=cellDetails[i-1][j+1].g+1.0;
				hNew=calculateHeuristic(i-1,j+1,dest);
				fNew=gNew+hNew;
				if(cellDetails[i-1][j+1].f=FLT_MAX || cellDetails[i-1][j+1].f<fNew){
					openList.insert(make_pair(fNew,make_pair(i-1,j+1));
					cellDetails[i-1][j+1].f=fNew;
					cellDetails[i-1][j+1].g=gNew;
					cellDetails[i-1][j+1].h=hNew;
					cellDetails[i-1][j+1].parent_i=i;
					cellDetails[i-1][i+1].parent_j=j;
					
				}
			}
		}
		//6th Successor NW
		if(isValid(i-1,j-1)==true){
			if(isDestination(i-1,j-1,dest)==true){
				cellDetails[i-1][j-1].parent_i=i;
				cellDetails[i-1][j-1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
				
			}
			else if(closedList[i-1][j-1]==false && isUnblocked(grid,i-1,j-1)){
				gNew=cellDetails[i-1][j-1].g+1.0;
				hNew=calculateHeuristic(i-1,j-1,dest);
				fNew=gNew+hNew;
				if(cellDetails[i-1][j-1].f=FLT_MAX || cellDetails[i-1][j-1].f<fNew){
					openList.insert(make_pair(fNew,make_pair(i-1,j-1));
					cellDetails[i-1][j-1].f=fNew;
					cellDetails[i-1][j-1].g=gNew;
					cellDetails[i-1][j-1].h=hNew;
					cellDetails[i-1][j-1].parent_i=i;
					cellDetails[i-1][j-1].parent_j=j;			
				}
			}
		}
		
		//7th Successor SW
		if(isValid(i+1,j-1)==true){
			if(isDestination(i+1,j-1,dest)==true){
				cellDetails[i+1][j-1].parent_i=i;
				cellDetails[i+1][j-1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
				
			}
			else if(closedList[i+1][j-1]==false && isUnblocked(grid,i+1,j-1)){
				gNew=cellDetails[i+1][j-1].g+1.0;
				hNew=calculateHeuristic(i+1,j-1,dest);
				fNew=gNew+hNew;
				if(cellDetails[i+1][j-1].f=FLT_MAX || cellDetails[i+1][j-1].f<fNew){
					openList.insert(make_pair(fNew,make_pair(i+1,j-1));
					cellDetails[i+1][j-1].f=fNew;
					cellDetails[i+1][j-1].g=gNew;
					cellDetails[i+1][j-1].h=hNew;
					cellDetails[i+1][j-1].parent_i=i;
					cellDetails[i+1][j-1].parent_j=j;			
				}
			}
		}
				//8th Successor SE
		if(isValid(i+1,j+1)==true){
			if(isDestination(i+1,j+1,dest)==true){
				cellDetails[i+1][j+1].parent_i=i;
				cellDetails[i+1][j+1].parent_j=j;
				cout<<"\nDestination cell is found"<<endl;
				tracePath(cellDetails,dest);
				foundDest=true;
				return;
				
			}
			else if(closedList[i+1][j+1]==false && isUnblocked(grid,i+1,j+1)){
				gNew=cellDetails[i+1][j+1].g+1.0;
				hNew=calculateHeuristic(i+1,j+1,dest);
				fNew=gNew+hNew;
				if(cellDetails[i+1][j+1].f=FLT_MAX || cellDetails[i+1][j+1].f<fNew){
					openList.insert(make_pair(fNew,make_pair(i+1,j+1));
					cellDetails[i+1][j+1].f=fNew;
					cellDetails[i+1][j+1].g=gNew;
					cellDetails[i+1][j+1].h=hNew;
					cellDetails[i+1][j+1].parent_i=i;
					cellDetails[i+1][j+1].parent_j=j;			
				}
			}
		}
    }
	if(foundDest==false)
		cout<<"\nNot found the cell"<<endl;
	
	return;
}



int main(){

    int grid[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };
 
    // Source is the left-most bottom-most corner
    Pair src = make_pair(8, 0);
 
    // Destination is the left-most top-most corner
    Pair dest = make_pair(0, 0);
 
    aStar(grid, src, dest);
 
    return(0);

}