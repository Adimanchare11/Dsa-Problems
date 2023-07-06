#include<stack>
#include <iostream>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    if(input.size()<=1) return;

    int lastelement= input.top();
    input.pop();

    reverseStack(input, extra);
    
    while(!input.empty())
    {
        int top= input.top();
        input.pop();
        extra.push(top);
    }

    input.push(lastelement);

    while(!extra.empty())
    {
        int top= extra.top();
        extra.pop();
        input.push(top);
    }
}



int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}