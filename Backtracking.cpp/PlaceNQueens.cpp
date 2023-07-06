#include<iostream>
#include<string.h>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col)
{

    //for same column

    for(int i=row-1; i>=0; i--)
    {
        if(board[i][col]==1) return false;
    }

    //Upper left diagonal

    for(int i=row-1,j= col-1; i>=0 && j>=0; i--,j--)
    {
         if(board[i][j]==1) return false;
    }

    //Upper right daigonal

    for(int i= row-1, j=col+1; i>=0 && j<n; i--, j++)
    {
        if(board[i][j]==1) return false;
    }
    return true;
}

void nQHelper(int n,int row)
{
    if(row==n)
    {
        //we have reached some solution
        //print the solution
        //return
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }   

    //place at all the possible positions and move to smaller problem

    for(int j=0; j<n; j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j]=1;
            nQHelper(n,row+1);
            board[row][j]=0;
        }
    }

}

void placeNQueens(int n)
{
    memset(board, 0, sizeof(int));
    nQHelper(n,0);

}

int main(){
    int n;
    cout<<"enter Number of queens: ";
    cin>>n;
    placeNQueens(n);
    return 0;
}