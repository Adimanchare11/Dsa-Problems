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
Node* reversell(Node* head)
{
    if(head==NULL || head->next==NULL) return head;

    Node* smalloutput= reversell(head->next);
    Node* temp= head;

    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    temp->next=head;
    head->next==NULL;
    return smalloutput;
}
Node* reverseLL_Iterative(Node* head)
{
    Node* prev= NULL;
    Node* curr= head;

    while(curr!=NULL)
    {
        Node* nextnode= curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    head=prev;
    return head;
}

Node* reverseLL2(Node* head)
{
    if(head==NULL || head->next==NULL) return head;

    Node* smalloutput= reverseLL2(head->next);
    Node* tail= head->next;
    tail->next=head;
    head->next=NULL;
    return smalloutput;
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


int main(){
    cout<<"Enter the elements: ";
    Node* head= takeInput();
    head= reverseLL2(head);
    cout<<"Reverse LL is: ";
    print(head);
}