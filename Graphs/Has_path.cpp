#include<iostream>
#include<queue>
using namespace std;

bool hasPath(int v, bool ** edges, bool* visited, int v1, int v2 )
{
    if(v1>=v || v2>=v){
        return false;
    }
    if(v1==v2) return true;

    if(edges[v1][v2] || edges[v2][v1]){
        return true;
    }

    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1]= true;

    while(!pendingVertices.empty()){

        for(int i=0; i<v; i++){
            if(i==pendingVertices.front()){
                continue;
            }
            if(visited[i]){
                continue;
            }
            if(edges[pendingVertices.front()][i]){
                pendingVertices.push(i);
                visited[i]= true;
            }
        }

        pendingVertices.pop();
        if(visited[v2]){
            return true;
        }
    }
    return false;
}

int main(){
    int v,e;
    cout<<"Total number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter Edegs: "<<endl;

    bool **edges= new bool*[v];
    for(int i=0; i<v; i++)
    {
        edges[i]= new bool[v];
        for(int j=0; j<v; j++)
        {
            edges[i][j]=false;
        }
    }

    for(int i=0; i<e; i++)
    {
        int start, end;
        cin>>start>>end;

        edges[start][end]==true;
        edges[end][start]==true;
    }

    bool* visited= new bool[v];
    for(int i=0; i<v; i++)
    {
        visited[i]= false;
    }

    int v1, v2;
    cout<<"Enter vertices to check edge: ";
    cin>>v1>>v2;

    if(hasPath(v,edges, visited,v1, v2))
    {
        cout<<"true";
    }
    else  cout<<"false";

    return 0;
}