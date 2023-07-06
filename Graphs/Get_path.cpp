#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> getPath(int v, bool** edges, bool* visited, int v1, int v2){
    vector<int> path;

    if(v1==v2){
        path.push_back(v1);
        return path;
    }

    for(int i=0; i<v; i++){

        if(i==v1) continue; 

        if(visited[i]) continue;

        if(edges[v1][i]){
            visited[i]= true;
            path = getPath(v, edges, visited,i, v2);
            if(path.size()){
                path.push_back(v1);
                return path;
            }
        }
    }
    return path;
}

int main(){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edgesL: ";
    cin>>e;

    cout<<"Enter Edges: "<<endl;
    bool** edges = new bool *[v];
    for(int i=0; i<v; i++){
        edges[i]= new bool [v];
        for(int j=0 ; j<v; j++){
            edges[i][j] = false;
        }
    }

    for(int i=0; i<e; i++){
        int first, second;
        cin>>first>>second;
        edges[first][second]= true;
        edges[second][first]= true;
    }

    bool * visited= new bool[v];
    for(int i=0 ; i<v; i++){
        visited[i]= false;
    }

    int v1, v2;
    cout<<"Enter vertices to get path between: ";
    cin>>v1>>v2;

    visited[v1] = true;
    vector<int> path = getPath(v, edges,visited, v1, v2);
    if (path.size())
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
   

    return 0;
}