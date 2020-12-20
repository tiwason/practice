#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void leastAvgSubArr(vector<int>& vec, int k)
{ 
    int sum=0;
    int index=0;
    for(int i =0; i<k; i++)
        sum = sum+vec[i];
    
    for(int i=k; i<vec.size(); i++)
    {
        int currSum = sum - vec[i-k] + vec[k];
        if(currSum < sum)
        {
            sum = currSum;
            index = i-k+1;
        }
    }
   cout << index <<" "<< index+k-1 <<endl;
}

int main()
{
    vector<int> vec = {3, 7, 5, 20, -10, 0, 12};//2
    //vector<int> vec = {3, 7, 90, 20, 10, 50, 40};//3
    int k = 2;

    leastAvgSubArr(vec ,k);

    return 0;
}