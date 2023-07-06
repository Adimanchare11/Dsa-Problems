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

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    head = prev;
    return head;
}

Node *NextLargeNumber(Node *head)
{
    head= reverse(head);
    Node* Curr= head;
    bool f= true;

    while(Curr!=NULL && f== true)
    {
        if(Curr->next==NULL && Curr->data==9)
        {
            Curr->data=1;
            Node* temp= new Node(0);
            temp->next=head;
            head=temp;
            Curr= Curr->next;
        }
        else if(Curr->data==9)
        {
            Curr->data= 0;
            Curr= Curr->next;
        }
        else
        {
            Curr->data= Curr->data+1;
            Curr= Curr->next;
            f=false;
        }
    }
    head = reverse(head);
    return head;
}
int main()
{
    Node *head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}