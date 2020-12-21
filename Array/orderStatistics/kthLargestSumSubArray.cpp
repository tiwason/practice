#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>


using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

void kthLargestSumSubArr(vector<int> vec, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int sum = vec[0];
    minHeap.push(vec[0]);

    for (int i=1; i<vec.size(); i++) //push first k sums in minheap
    {
        sum = sum + vec[i];
        if (sum > minHeap.top() || minHeap.size() < k)
        {
            if (minHeap.size() == k)
                minHeap.pop();

            minHeap.push(sum);
        }       
    }
    cout << k <<"th Largest sum of sub array is : " << minHeap.top() << endl;
}


int main()
{
    //vector<int> vec = {20, -5, -1}; //3 //14
    vector<int> vec = {10, -10, 20, -40}; //6 //-10

    kthLargestSumSubArr(vec, 6);
    return 0;
}