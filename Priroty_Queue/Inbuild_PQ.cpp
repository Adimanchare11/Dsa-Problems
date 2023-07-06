#include<iostream>
#include<queue>
using namespace std;

int main(){
    //Max Heap
    cout<<"MAX HEAP ";
    priority_queue<int> pq;

    pq.push(150);
    pq.push(500);
    pq.push(100);
    pq.push(50);
    pq.push(450);
    pq.push(750);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<"MAX: "<<pq.top()<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<endl;

    //Min Heap
    priority_queue<int, vector<int>, greater<int>> p;
    cout<<"MIN HEAP";
    p.push(150);
    p.push(500);
    p.push(100);
    p.push(50);
    p.push(450);
    p.push(750);

    cout<<"Size: "<<p.size()<<endl;
    cout<<"Min: "<<p.top()<<endl;

    while(!p.empty())
    {
        cout<<p.top()<<endl;
        p.pop();
    }
    
    
    return 0;
}