#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <queue>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        std::cout << elem <<" ";
    }
    std::cout<< endl;
}

void findMedianOfElems(const vector<int>& vec)
{
    priority_queue<int> maxHeap; //stores first half
    priority_queue<int, vector<int>, greater<int> > minHeap; //stores second half
    double median = vec[0];

    for(const auto &e: vec)
    {
       if (maxHeap.size() > minHeap.size())
       {
           if (e < median)
           {
                minHeap.push(maxHeap.top());
                maxHeap.push(e);
                maxHeap.pop();
           }
           else
                minHeap.push(e);
            median = (maxHeap.top() + minHeap.top())/2.0;
       }
       else if(maxHeap.size() == minHeap.size())
       {
           if (e > median)
            {    
                minHeap.push(e);
                median = minHeap.top();
            }
            else
            {
               maxHeap.push(e);
               median = maxHeap.top();
            }   
       }
       else
       {
           if (e > median)
           {
               maxHeap.push(minHeap.top());
               minHeap.pop();
               minHeap.push(e);
           }
           else
               maxHeap.push(e);
           median = (maxHeap.top() + minHeap.top())/2.0;
       }
       cout << median << " ";
    }
    std::cout <<endl;
}

int main()
{
    //vector<int> vec = {5, 10, 15};
   vector<int> vec = {1, 2, 3, 4};
    //vector<int> vec = {5, 15, 10, 20, 3};
   
    findMedianOfElems(vec);
    return 0;
}