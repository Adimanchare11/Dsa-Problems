// You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
// You don't need to double the capacity.

#include<iostream>
using namespace std;
class dequeue
{
    int *deq;
    int front;
    int rear;
    int si;

public:
    dequeue(int size)
    {
        deq = new int[size];
        si = size;
        front = -1;
        rear = -1;
    }

    void insertFront(int ele)
    {

        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            deq[front] = ele;
            return;
        }
        // cout<<"front="<<front<<" rear="<<rear<<endl;
        if ((front + 1) % si == rear)
        {
            cout << (-1) << endl;
            return;
        }
        front = (front + 1) % si;
        deq[front] = ele;
    }

    void insertRear(int ele)
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            deq[rear] = ele;
            return;
        }
        // cout<<"front="<<front<<" rear="<<rear<<endl;
        if (front == rear - 1 || rear == 0 && front == si - 1)
        {
            cout << (-1) << endl;
            return;
        }
        if (rear == 0)
            rear = si - 1;
        else
            rear--;
        deq[rear] = ele;
    }
    void deleteFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << (-1) << endl;
            return;
        }
        if (rear == front)
        {
            rear = -1;
            front = -1;
            return;
        }
        if (front == 0)
            front = si - 1;
        else
            front--;
    }

    void deleteRear()
    {
        if (front == -1 && rear == -1)
        {
            cout << (-1) << endl;
            return;
        }
        if (rear == front)
        {
            rear = -1;
            front = -1;
            return;
        }
        rear = (rear + 1) % si;
    }

    int getFront()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        return deq[front];
    }
    int getRear()
    {
        if (front == -1 && rear == -1)
        {
            return -1;
        }
        return deq[rear];
    }
};

int main(){
    
    dequeue dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}