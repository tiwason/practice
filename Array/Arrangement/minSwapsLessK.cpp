#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

int findMinSwaps(vector<int> vec, int k)
{
    int count = 0;
    int minCount = INT_MAX;

    for (auto const &e : vec)
    {
        if (e <= k)
            count ++;
    }

    int start = 0, end = count-1;

    while (end != vec.size())
    {  
        int i=0;
        int tmp = 0;

        for (int i=start; i <= end; i++)
        {
            if (vec[i] > k)
                tmp++;
        }
        if(tmp < minCount)
            minCount = tmp;
       
        start++;
        end++;
    }
   
   return minCount;
}

int main()
{
    //vector<int> vec = {2, 1, 5, 6, 3}; //3 //1
    vector<int> vec = {2, 7, 9, 5, 8, 7, 4}; //5 //2
  
    cout << "Minimum Swaps : " << findMinSwaps(vec, 5) <<endl;;
    return 0;
}