#include<iostream>
using namespace std;

class Edge{
public:
int source;
int dest;
int weight; 

};

int main(){
    int v, E;
    cout<<"Enter number of vertices: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>E;

    Edge * input = new Edge[E];

    cout<<"Enter edge and it's weight: "<<endl;
    for(int i=0; i<E; i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    
    return 0;
}