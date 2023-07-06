#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackUSingArray
{
    int *data;
    int nextindex;
    int capacity;

public:
    StackUSingArray()
    {
        data = new int[4];
        nextindex = 0;
        capacity = 4;
    }

    // Return the number of element present in the stack
    int size()
    {
        return nextindex;
    }

    // Is empty
    bool isempty()
    {
        //     if(nextindex==0)  return true;
        //     else return false;
        return nextindex == 0;
    }

    // insert element
    void push(int element)
    {
        if (nextindex == capacity)
        {
            // cout << "stack is full" << endl;
            // return;
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity*=2;
            delete[] data;
            data=newdata;
        }
        data[nextindex] = element;
        nextindex++;
    }

    // delete element
    int pop()
    {
        if (isempty())
        {
            cout << "Stack is  empty";
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    // returns the element present at the top
    int top()
    {
        return data[nextindex - 1];
    }
};

int main()
{
    StackUSingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isempty() << endl;

    return 0;
}