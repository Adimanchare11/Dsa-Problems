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

void print(Node* head)
{
    Node* temp= head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

Node* merge(Node* h1, Node* h2)
{
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;

    Node* newhead= NULL;
    Node* newtail= NULL;
    if(h1->data<=h2->data)
    {
        newhead=h1;
        newtail=h1;
        h1=h1->next;
    }
    else
    {
        newhead=h2;
        newtail=h2;
        h2=h2->next;
    }

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<h2->data)
        {
            newtail->next=h1;
            newtail=newtail->next;
            h1= h1->next;
        }
        else
        {
            newtail->next=h2;
            newtail=newtail->next;
            h2=h2->next;
        }
    }

    if(h1!=NULL)
    {
        newtail->next=h1;
    }
    if(h2!=NULL)
    {
        newtail->next=h2;
    }
    return newhead;
}

int main(){
    cout<<"Enter first sorted LL: ";
    Node* h1= takeInput();
    cout<<"Enter second sorted LL: ";
    Node* h2= takeInput();
    Node* head= merge(h1,h2);
    cout<<"Sorted Merged LL: ";
    print(head);
    return 0;
}