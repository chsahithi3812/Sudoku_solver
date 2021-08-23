#include<iostream>
#include<bits/stdc++.h>
// this works on backtracing algrithm
void displaysud(int g[9][9]);//displays the sudoku
bool findzero(int g[9][9], int &r, int &c);//empty spaces are initialised to zeroes
bool presentincol(int g[9][9],int col,int num);//number present in coloum
bool presentinrow(int g[9][9],int row,int num);//number present in row
bool presentinbox(int g[9][9],int row,int col,int num );//number present in 3*3 box
bool valid(int g[9][9],int row,int col,int num);//number to be valid or not
bool solvesudoko(int g[9][9]);
using namespace std;
int main()
{
    int i,j,g[9][9];
    cout<<"Enter the sudoko(0 for empty):: "<<endl;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin>>g[i][j];
        }}
    cout << endl;
  if (solvesudoko(g) == true) {
    cout << "Solution: " << endl;
    displaysud(g);
  } else {
    cout << "No solution exists. " << endl;  
  }
    return 0;
}
void displaysud(int g[9][9]){
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << g[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool findzero(int g[9][9], int &r, int &c){
   for (r = 0; r < 9; r++)
   for (c = 0; c < 9; c++)
   if (g[r][c] == 0)
   return true;
   return false;
   
}
bool presentincol(int g[9][9],int col,int num ){
    for (int row = 0; row < 9; row++)
    if (g[row][col] == num)
      return true;
  return false;
}
bool presentinrow(int g[9][9],int row,int num ){
    for (int col = 0; col < 9; col++)
    if (g[row][col] == num)
      return true;
  return false;
}
bool presentinbox(int g[9][9],int row,int col,int num ){
    int boxrow = row - row % 3;
  int boxcol = col - col % 3;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (g[boxrow + i][boxcol+ j] == num)
        return true;
  return false;
}
bool valid(int g[9][9],int row,int col,int num){
   return !presentinrow(g,row,num) && !presentincol(g,col,num) && !presentinbox(g,row,col,num);
}
bool solvesudoko(int g[9][9]){
    int row, col;
   if (!findzero(g,row, col))
      return true; 
   for (int num = 1; num <= 9; num++){ 
      if (valid(g,row, col, num)){ 
         g[row][col] = num;
         if (solvesudoko(g)) 
            return true;
         g[row][col] = 0;
      }
   }
   return false;
}
