#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string,int> ourmap;

    ourmap["abc"]=1;
    ourmap["abc2"]=2;
    ourmap["abc3"]=3;
    ourmap["abc4"]=4;
    ourmap["abc5"]=5;
    ourmap["abc6"]=6;

    unordered_map<string,int>::iterator it= ourmap.begin();

    while(it!= ourmap.end())
    {
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
        it++;
    }

    //find
    unordered_map<string,int>::iterator it2= ourmap.find("abc");
    //ourmap.erase(it2, it2+4);  //for removing values 

    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator itv= v.begin();

    while(itv!=v.end())
    {
        cout<<*itv<<endl;
        itv++;
    }
    
    return 0;
}