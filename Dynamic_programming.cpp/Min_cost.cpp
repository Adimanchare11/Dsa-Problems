#include <iostream>
using namespace std;

int minCostPathHelper(int**input, int m, int n, int i, int j)
{
    //Base Case
    if(i==m-1 && j==n-1)
    {
        return input[i][j];
    }

    if(i>=n || j>=m)
    {
        return INT_MAX ;//(INT_MAX== Plus Infinity)
    }

    //recursive calls
    int x= minCostPathHelper(input, m, n,i,j+1);
    int y= minCostPathHelper(input,m,n,i+1,j+1);
    int z= minCostPathHelper(input, m, n, i+1,j);

    //small calculations
    int ans= min(x,min(y,z))+ input[i][j];
    return ans;
}

int minCostPath(int** input,int m, int n)
{
   return minCostPathHelper(input, m,n,0,0);
}

//Memoisation
int minCostPath2_Helper(int** input, int m, int n, int i, int j, int** output)
{
    if(i==m-1 && j==n-1)
    {
        return input[i][j];
    }

    if(i>=n || j>=m)
    {
        return INT_MAX;
    }

    if(output[i][j]!= -1)
    {
        return output[i][j];
    }

    int x= minCostPath2_Helper(input, m,n,i,j+1,output);
    int y= minCostPath2_Helper(input,m,n,i+1,j+1,output);
    int z= minCostPath2_Helper(input,m,n,i+1,j,output);

    int a= min(x,min(y,z))+ input[i][j];
    output[i][j]=a;
    return a;

}
int minCostPath2(int** input, int m, int n, int i, int j)
{
    int **output= new int*[m];
    for(int i=0; i<m; i++)
    {
        output[i]= new int [n];
        for(int j=0; j<n; j++)
        {
            output[i][j]= -1;
        }

    }
    return minCostPath2_Helper(input,m,n,i,j,output);

}

//DP
int minCostPath3(int** input, int );

int main()
{
    int **arr, m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    cout<<minCostPath(input, m,n)<<endl;
    cout<<"hello World";
    cout<<minCostPath2(input,m,n,0,0)<<endl;

    return 0;
}