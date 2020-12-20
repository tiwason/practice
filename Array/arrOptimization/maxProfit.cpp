#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& vec)
{
    vector<int> profit(vec.size(), 0);
    int n=vec.size();
   
     //R to L scan
    int maxm = vec[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if (vec[i] > maxm)
            maxm = vec[i];
        profit[i] = max(profit[i+1], (maxm - vec[i]));
    }

    //L to R scan
    int min = vec[0];
    for(int i=1; i<n; i++)
    {
        if (vec[i] < min)
            min = vec[i];

        profit[i] = max(profit[i-1], profit[i] + vec[i]-min);
    }

    return profit[n-1];
}

int main()
{
    //vector<int> vec = {10, 22, 5, 75, 65, 80};
    //vector<int> vec = {2, 30, 15, 10, 8, 25, 80};
    //vector<int> vec = {100, 30, 15, 10, 8, 25, 80};
    vector<int> vec = {90, 80, 70, 60, 50};

    cout << maxProfit(vec) << endl;

    return 0;
}