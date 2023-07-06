// You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

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
        cin>>data;
    }
    return head;
}

int length(Node* head)
{
    Node* temp =head;
    int count=0;
    while(temp!=NULL)
    {
        temp= temp->next;
        count++;
    }
    return count;
}

Node* appendLastNTofirst(Node* head, int n)
{
    
}
int main()
{
    Node* head= takeInput();
    cout<<"The length of the LL is: "<<length(head);
    return 0;
}