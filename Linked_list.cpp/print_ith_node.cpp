// For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data= data;
        this->next = NULL;
    }
};

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail= NULL;

    while(data!=-1)
    {
        Node* newnode= new Node(data);
        if(head==NULL)
        {
            head= newnode;
            tail= newnode;
        }
        else
        {
            tail->next= newnode;
            tail= tail->next;
        }
        cin>>data;
    }
    return head;
}

void printithNode(Node* head, int i)
{
    Node* Curr= head;
    int count=0;
    while(count<i && Curr!=NULL)
    {
        Curr= Curr->next;
        count++;
        if(count==i)
        {
            cout<<Curr->data;
        }
    }
}

int main(){
    int t;
    cout<<"Enter number of test cases: ";
    cin>>t;
    while(t--)
    {
        Node* head= takeInput();
        int pos;
        cout<<"Enter position: ";
        cin>>pos;
        printithNode(head,pos);
        cout<<endl;
        
    }
    return 0;
}