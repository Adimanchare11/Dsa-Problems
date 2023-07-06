// Given a Singly Linked List of integers, delete all the alternate nodes in the list.
#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteAlternateNodes(Node *head) {
    if(head==NULL) return;

    Node* prev=head;
    Node* Nextnode= head->next;
    
    while(prev!=NULL && Nextnode!=NULL)
    {
        prev->next=Nextnode->next;
        prev= prev->next;

        if(prev!=NULL)
        {
            Nextnode=prev->next;
        }
    }
}

int main(){
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
    
    return 0;
}