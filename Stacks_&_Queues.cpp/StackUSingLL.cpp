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

class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int element)
    {
        Node* newnode = new Node(element);
        newnode->next = head;
        head = newnode;
        size++;
    }

    int pop()
    {
        if(isEmpty()) return 0;
        int ans= head->data;
        Node* temp= head;
        head=head->next;
        delete temp;
        return ans;
    }

    int top()
    {
        if(isEmpty()) return 0;
        return head->data;
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.isEmpty() << endl;

    return 0;
}