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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Node *takeInput()
// {
//     int data;
//     cin>>data;

//     Node* head= NULL;
//     while(data!=-1)
//     {
//         Node* newnode= new Node(data);
//         if(head==NULL)
//         {
//             head=newnode;
//         }

//         else
//         {
//             Node* temp=head;
//             while(temp->next!=NULL)
//             {
//                 temp=temp->next;
//             }
//             temp->next=newnode;
//         }
//         cin>>data;
//     }
//     return head;
// }

Node *takeInput_better()
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

int main()
{
    Node *head = takeInput_better();
    print(head);
    return 0;
}