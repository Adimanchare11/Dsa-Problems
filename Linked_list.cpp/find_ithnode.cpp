// You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int findNode(Node *head, int n)
{
    Node* Current= head;
    int count=0;
    while(Current!=NULL)
    {
        if(Current->data==n) return n;
        count++;
        Current= Current->next;
    }
    return -1;
}

int main()
{
    Node* head= takeInput();
    int n;
    cout<<"Enter the data: ";
    cin>>n;
    findNode(head,n);

    return 0;
}