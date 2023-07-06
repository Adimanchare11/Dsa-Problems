#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

class PrirorityQueue
{
    vector<int> pq;

public:
    PrirorityQueue()
    {
    }

    int getsize()
    {
        return pq.size();
    }

    bool isempty()
    {
        return pq.size()==0;
    }

    int getMin()
    {
        if (pq.size() == 0)
            return INT_MIN;
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
    if(isempty())
    { 
        return 0;
    }

    int ans= pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();

    int parentIndex=0;
    int LeftchildIndex= 2 * parentIndex + 1;
    int RightChildIndex = 2 * parentIndex + 2;

    	// if(isEmpty()) {
		// 	return 0;		//  we will check if Priority Queue is empty
		// }
		// int ans = pq[0];
		// pq[0] = pq[pq.size() - 1]; // replace the main with the root node
		// pq.pop_back();// we will remove the element
        // int parentIndex = 0; // down heap
		// int leftChildIndex = 2 * parentIndex + 1;// for leftchild 
		// int rightChildIndx = 2 * parentIndex + 2;// for rightchild

    while(LeftchildIndex<pq.size())
    {
        int minIndex= parentIndex;

        if(pq[minIndex]>pq[LeftchildIndex])
        {
            minIndex=LeftchildIndex;
        }

        if(RightChildIndex<pq.size() &&  pq[RightChildIndex]<pq[minIndex])
        {
            minIndex= RightChildIndex;
        }

        if (minIndex == parentIndex) {
          break;
        }

        int temp = pq[minIndex];
        pq[minIndex] = pq[parentIndex];
        pq[parentIndex] = temp;

        parentIndex = minIndex;
        int LeftchildIndex = 2 * parentIndex + 1;
        int RightChildIndex = 2 * parentIndex + 2;
    }
    return ans;
    }

    // while(leftChildIndex < pq.size()) { // to check so that the it should not overflow and leftchild will act as leaf child
	// 		int minIndex = parentIndex; // minindex to check the minimum element of three left, right and parent

	// 		if(pq[minIndex] > pq[leftChildIndex]) { 
	// 			minIndex = leftChildIndex; 
	// 		}

	// 		if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
	// 			minIndex = rightChildIndx;
	// 		}

	// 		if(minIndex == parentIndex) { // it will not excute if left and right have children
	// 			break;
	// 		}
    
	// 		int temp = pq[minIndex]; // now we will do swapping
	// 		pq[minIndex] = pq[parentIndex];
	// 		pq[parentIndex] = temp;
		
	// 		parentIndex = minIndex;
	// 		leftChildIndex = 2 * parentIndex + 1;
	// 		rightChildIndx = 2 * parentIndex + 2;
	// 	}

	// 	return ans;
    // }

    

};
int main()
{
    PrirorityQueue pq;
    pq.insert(10);
    pq.insert(15);
    pq.insert(5);
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    cout<<"Hello World";
    cout<< pq.getsize()<<endl;
    cout<<pq.getMin()<<endl;
    while(!pq.isempty())
    {
        cout<<pq.removeMin()<<endl;
    }
    cout<<"Hello World";
    cout<<endl;
    return 0;
}