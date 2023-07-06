#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> GetConnectedComponents(int n, int** edges, int start, bool* visited){
    queue<int> vertices;
    vector<int> ans;
    
    vertices.push(start);
    visited[start]= true;
    while(!vertices.empty()){
        int current = vertices.front();
        ans.push_back(current);
        vertices.pop();

        for(int i=0; i<n; i++){
            if(!visited[i] && edges[current][i]==1 && i!=current){
                vertices.push(i);
                visited[i]= true;
            }
        }
    }
    return ans;
}

vector<vector<int>> getans(int n,  int** edges, bool * visited){
    vector<vector<int>> components;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> ans= GetConnectedComponents(n,edges,i,visited);
            components.push_back(ans);
        }
    }
    return components;
}

int main(){
    int v, e;
    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<"Enter number of Edges: ";
    cin>>e;
    cout<<"Enter edges: "<<endl;

    int ** edges= new int* [v];
    for(int i=0; i<v; i++){
        edges[i]= new int[v];
        for(int j=0; j<v; j++)
        {
            edges[i][j]= 0;
        }
    }

    for(int i=0; i<e; i++){
        int start, end;
        cin>>start>>end;
        edges[start][end]=1;
        edges[end][start]=1;
    }

    bool* visited =new bool [v];
    for(int i=0; i<v; i++){
        visited[i]=false;
    }

    vector<vector<int>> components = getans(v,edges,visited);

    for(int i=0; i<components.size(); i++){
        sort(components[i].begin(), components[i].end()); // sorting individual vectors
        for(int j=0; j<components[i].size(); j++){
            cout<<components[i][j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}