// You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.

// A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).
// The tickets are sold in the following manner :
// 1. The first person (pi) in the queue requests for the ticket.
// 2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
// 3. Otherwise, give him the ticket (and don't make him stand in queue again).

// Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.

// Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.

#include <iostream>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
    queue<int> peoplequeue;
    priority_queue<int> maxheap;

    for (int i = 0; i < n; i++)
    {
        peoplequeue.push(arr[i]);
        maxheap.push(arr[i]);
    }

    int count = 0;
    while (!maxheap.empty())
    {
        if (peoplequeue.front() == maxheap.top())
        {
            if (k == 0)
            {
                return count + 1;
            }
            else
            {
                count++;
                peoplequeue.pop();
                maxheap.pop();
                k--;
            }
        }
        else
        {
            peoplequeue.push(peoplequeue.front());
            peoplequeue.pop();
            if(k==0)
            {
                k=peoplequeue.size()-1;
            }
            k--;
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Number of costumers in the list: ";
    cin >> n;

    int *arr = new int[n];

    cout<<"Enter costumer priorites according to the list : ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"Enter costumer number in list: ";
    int k;
    cin >> k;

    cout << "This costumer will get ticket after "<<buyTicket(arr, n, k)<<"sec";

    delete[] arr;

    return 0;
}