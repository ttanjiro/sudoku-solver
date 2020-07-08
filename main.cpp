#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define UNASSIGNED 0
#define N 9
int pp = 0;


bool FindUnassignedLocation(int grid[N][N],int &row,int &col);
bool isSafe(int grid[N][N],int row,int col, int num);

void printSudoku(int grid[N][N]){

   for(int row=0;row<N;row++){
       for(int col=0;col<N;col++){
          cout<<grid[row][col]<<" ";
       }
     cout<<"\n";
   }
}

 bool solveSudoku(int grid[N][N])
 {

    // cout<<"Entered"<<endl;
     int row, col;
     if(!FindUnassignedLocation(grid,row,col))
        return true;

     for(int num=1; num<=9;num++){
        if(isSafe(grid,row,col,num)){

            grid[row][col] = num;
             printSudoku(grid);
             cout<<endl;
            if(solveSudoku(grid)==true)
                return true;
            grid[row][col] = UNASSIGNED;

        }

    }

   return false;
}


bool FindUnassignedLocation(int grid[N][N],int &row,int &col)
{
  for(row=0;row<9;row++){
       for(col=0;col<9;col++){
              if(grid[row][col]==UNASSIGNED)
                return true;
        }
  }

   return false;
}



bool usedInRow(int grid[N][N],int row,int num){
   for(int col=0;col<N;col++){
      if(grid[row][col]==num)
        return true;
   }

   return false;
}
bool usedInCol(int grid[N][N],int col,int num){
  for(int row=0;row<N;row++)
    if(grid[row][col] == num)
        return true;


  return false;
}

bool usedInBox(int grid[N][N],int startRow,int startCol,int num){

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(grid[row+startRow][col+startCol] == num)
                return true;
        }
    }

   return false;
}


bool isSafe(int grid[N][N],int row,int col, int num){

    return !usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInBox(grid,row-row%3,col-col%3,num);


}





int main(){

  int grid[N][N] =   {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};



     if(solveSudoku(grid)==true)
                    printSudoku(grid);
     else cout<<"No Solution Exists "<<endl;

 // cout<<pp;

}
