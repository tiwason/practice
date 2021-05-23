#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;
typedef pair<int, int> range;

int block = 1;

bool compare(const range &a, const range &b)
{
    if(a.first/block != b.first/block)
        return (a.first/block < b.first/block);
    
    return (a.second < b.second);
}

void findSumQueryRanges(vector<int>& arr, vector<range>& queries)
{
    int size = arr.size();
    block = (int)sqrt(size);

    sort(queries.begin(), queries.end(), compare);

    int sum=0;
    int currL =0, currR=0;

    for(int q=0; q<queries.size(); q++)
    {
        int left = queries[q].first;
        int right = queries[q].second;

        while (currL < left)
        {
            sum -= arr[currL];
            currL++;
        }

        while (currL > left)
        {
            sum += arr[currL];
            currL--;
        }

        while (currR <= right)
        {
            sum += arr[currR];
            currR++;
        }

        while(currR > right+1)
        {
            sum -= arr[currR];
            currR--;
        }

        cout << left << " : " << right << " = " << sum << endl;
    }
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    vector<range> queries = { {0, 4}, {1, 3}, {2, 4}};

    findSumQueryRanges(arr, queries);
    return 0;
}