// For a given singly linked list of integers, find and return its length. Do it using an iterative method.

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

// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }
int length(Node *head)
{
    Node *temp = head;
    int count=0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//Recursively
int length_rec(Node* head)
{
    if(head==NULL) return 0;
    else 
    { return 1+length_rec(head->next);}
}

int main()
{
    int t;
    cout << "Enter Number of test cases: ";
    cin >> t;

    while (t--)
    {
        cout<<"Enter elements: ";
        Node *head = takeInput();
        cout <<"Length of the linked list is: "<<length_rec(head) << endl;
    }
    return 0;
}