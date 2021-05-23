#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct IterInfo
{
    vector<int>::const_iterator current;
    vector<int>::const_iterator end;

    bool operator > (const IterInfo& iterI) const
    {
        return (*current > *iterI.current);
    }
};


void sortKsorted(vector<vector<int>>& input, vector<int> &result)
{
    priority_queue<IterInfo, vector<IterInfo>, greater<IterInfo> > minHeap;

    for (auto & arr : input)
        minHeap.emplace(IterInfo{arr.cbegin(), arr.cend()});

    while(!minHeap.empty())
    {
        auto currArr = minHeap.top();
        minHeap.pop();

        result.push_back(*currArr.current);
        cout << *currArr.current <<" ";
        ++currArr.current;
        if (currArr.current != currArr.end)
        {
            minHeap.emplace(IterInfo{currArr.current, currArr.end});
        }
    }
    cout <<endl;
}

int main()
{
    vector<vector<int>> input = {{3,5,7,9,16,28}, {0, 6, 13}, {0, 6}};
    vector<int> result;
    sortKsorted(input, result);

    for (auto& a : result)
        cout << a <<" ";

    cout <<endl;

    return 0;
}