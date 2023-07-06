#include <queue>
#include <iostream>
using namespace std;

void printBFS(int n, int** edges, int sv, bool* visited){
    queue<int> pendingvertices;

    pendingvertices.push(sv);
    visited[sv]=true;

    while(!pendingvertices.empty() ){
        int currentvertex= pendingvertices.front();
        cout<<currentvertex<<"->";
        pendingvertices.pop();

        for(int i=0; i<n; i++)
        {
            if(i==currentvertex){
                continue;
            }
            if(edges[currentvertex][i]==1  && !visited[i]){
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }

}

int main()
{

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
    printBFS(n,edges,0, visited);
    return 0;

    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}