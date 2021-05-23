#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

class compare
{
    public:
        bool operator () (const pair<int,int>& p1, const pair<int, int>& p2)
        {
            if(p1.second == p2.second)
                return (p1.first < p2.first);
            
            return (p1.second < p2.second);
        }
};

bool compareFunc(const pair<int,int>& p1, const pair<int, int>& p2)
{
    if(p1.second == p2.second)
        return (p1.first < p2.first);
            
    return (p1.second < p2.second);
}

void findKMostFrequent(const vector<int>& vec, int k)
{
    unordered_map<int, int> hash;
    priority_queue< pair<int, int>, vector< pair<int, int> >,  compare> maxHeap;

    for(const auto& e: vec)
        hash[e]++;

    for (const auto &e: hash)
        maxHeap.push({e.first, e.second});
    
    for (int i=1; i<=k ; i++)
    {
        cout << maxHeap.top().first <<" "<< maxHeap.top().second <<endl;
        maxHeap.pop();
    }
}

int main()
{
    //vector<int> vec = {3, 1, 4, 4, 5, 2, 6, 1}; //2
    vector<int> vec = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}; //4

    findKMostFrequent(vec, 4);
    return 0;
}