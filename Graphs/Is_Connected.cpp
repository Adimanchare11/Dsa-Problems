#include<iostream>
#include<queue>
using namespace std;

bool isConnected(int n, bool** edges, int start, bool* visited){
    queue<int> vertices;
    vertices.push(start);
    visited[start]= true;

    while(!vertices.empty()){
        int current= vertices.front();
        vertices.pop();
        for(int i=0; i<n; i++){
            if(!visited[i] && edges[current][i] && i!=current){
                vertices.push(i);
                visited[i]= true;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int v,e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter Edges:" <<endl;
    bool** edges = new bool*[v];
    for(int i=0; i<v; i++)
    {
        edges[i]= new bool[v];
        for(int j=0;j<v; j++){
            edges[i][j]= false;
        }
    }

    for(int i=0; i<e; i++){
        int start, end;
        
        cin>>start>>end;
        edges[start][end]= true;
        edges[start][end]= true;
    }

    bool * visited= new bool[v];
    for(int i=0; i<v; i++){
        visited[i]= false;
    }

    if(isConnected(v,edges,0,visited)){
        cout<<"The graph is a Connected graph ";
    }
    else cout<<"The graph is a DisConnected graph ";
    return 0;
}