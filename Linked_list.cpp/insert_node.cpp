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
            temp=temp->next;
        }
 };

Node* Insert_node(Node* head, int i, int data)
{
    Node* newnode= new Node(data);
    int count=0;
    Node* temp=head;

    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }

    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
    }

    if(temp!=NULL)
    {
        newnode->next=temp->next;
        temp->next= newnode;
    }
    return head;
}

Node* InsertNode_rec(Node* head, int data, int i)
{
    if(head==NULL) return head;
    
    if(i==0)
    {
        Node* newnode= new Node(data);
        newnode->next= head;
        head= newnode;
    }

    else if(i==1)
    {
        Node* newnode= new Node(data);
        Node* temp= head->next;
        head->next= newnode;
        newnode->next=temp;
        return head;
    }
    else InsertNode_rec(head->next, data, i-1);

    return head;
}

// Delete Node

Node* Delete_node(Node* head, int pos)
{
    Node* temp= head;
    int count=0;
    if(pos==0)
    {
        head= temp->next;
        delete temp;
        return head;
    }

    while(temp->next!=NULL && count<pos-1)
    {
        temp= temp->next;
        count++;
    }
    if(temp->next!=NULL)
    {
        Node* a= temp->next;
        Node* b= a->next;
        temp->next=b;
        delete a;
    }
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
	if(head==NULL || head->next== NULL) return head;

	if(pos==0)
	{
        Node* Current= head;
		head= Current->next;
        delete Current;
		return head;
	}

    else if(pos==1)
    {
        Node* temp= head->next->next;
        delete head->next;
        head->next=temp;
        return head;
    }
	else deleteNodeRec(head->next, pos-1);
	return head;
}

int main(){
    int t;
    cout<<"Enter number of test cases: ";
    cin>>t;
    while(t--)
    {
        Node* head= takeInput();
        print(head);
        cout<<endl;
        // int i,data;
        // cout<<"Enter position and data: " ;
        // cin>>i>>data; 

        // head= InsertNode_rec(head,data,i);
        // print(head);
        int pos;
        cout<<"Enter Position: ";
        cin>>pos;

        head= deleteNodeRec(head, pos);
        print(head);
    }
    return 0;
}