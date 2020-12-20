#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int maxSumSubarraySize(vector<int>& vec)
{
   int currentSum = INT_MIN;
   int maxSum = INT_MIN;
   int i = 0;
   int start = 0;
   int end = 0;

   while(i < vec.size())
   {       
        if (currentSum < 0)
         {
            currentSum = 0;
            start = i;
            end = i;
         }

        if (currentSum + vec[i] > maxSum)
        {
            maxSum = currentSum + vec[i];
            end = i;
        }
        
        currentSum += vec[i];
        i++;
   }
   return (end - start+1);
}

int main()
{
    //vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3}; //5
    vector<int> vec = {1, -2, 1, 1, -2, 1}; //2

    cout << maxSumSubarraySize(vec) << endl;

    return 0;
}