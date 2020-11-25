#include <iostream>
#include <queue>

using namespace std;

void printVector(vector<int>& vec)
{
    vector<int>::iterator it;
    for(it=vec.begin(); it!=vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;
}

void kSorted(vector<int>& vec, int dist)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<=dist; i++)
        minHeap.push(vec[i]);
    
    for(int i=0; i<vec.size(); i++)
    {
        vec[i] = minHeap.top();
        minHeap.pop();

        if (i+dist+1 < vec.size())
            minHeap.push(vec[i+dist+1]);
    }
    printVector(vec);
}

int main()
{
    vector<int> vec = {6, 5, 3, 2, 8, 10, 9};
    //vector<int> vec = {10, 9, 8, 7, 4, 70, 60, 50};

    int k = 3; //4

    kSorted(vec, k);

    return 0;
}