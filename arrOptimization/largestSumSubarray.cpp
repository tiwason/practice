#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSumSubarray(vector<int>& vec)
{
   int currentSum = INT_MIN;
   int maxSum = INT_MIN;
   int i = 0;

   while(i < vec.size())
   {       
        if (currentSum < 0)
            currentSum = 0;

        if (currentSum + vec[i] > maxSum)
            maxSum = currentSum;
        
        currentSum += vec[i];
        i++;
   }
   return maxSum;
}

int main()
{
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << maxSumSubarray(vec) << endl;

    return 0;
}