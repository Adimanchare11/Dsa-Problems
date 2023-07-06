#include<iostream>
using namespace std;

void printDFS(int n, int** edges, int sv, bool* visited ){
    cout<<sv; //printing starting vertex
    cout<<"->";
    visited[sv]= true; //making starting vertex as visited

    for(int i=0; i<n; i++){
        if(i==sv){
            continue; //if i and starting vertex are same then will skip it and move forward
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            printDFS(n,edges,i, visited);
        
        }
    }
}

int main(){
    int n, e;
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter number of edges:";
    cin>>e;

    cout<<"Enter Edges:"<<endl;
    int ** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for (int j=0; j<n; j++)
        {
            edges[i][j]= 0; //filling the 2d array with 0's  initially 
        }
    }

    for(int i=0; i<e; i++)
    {
        int f,s;  //first index and second index
        cin>>f>>s;
        edges[f][s]=1; //filling visited edges with 1
        edges[s][f]=1;
    }
    bool *visited = new bool[n];
    for(int i=0 ; i<n; i++){
        visited[i]= false;
    }

    cout<<"The path will be:";
    printDFS(n,edges,0, visited);
    return 0;

}