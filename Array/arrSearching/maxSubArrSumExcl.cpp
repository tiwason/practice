#include <iostream>
#include <unordered_set>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int maxSubArraySum(int arr1[], int size1, int arr2[], int size2)
{
   int currSum=0, maxSum = INT32_MIN;
   unordered_set<int> hash;

    for(int i =0; i<size2; i++)
        hash.insert(arr2[i]);
    
    for(int j=0; j < size1; j++)
    {   
        if (currSum<0 || hash.find(arr1[j]) != hash.end())
            currSum = 0;
        
        currSum = max(arr1[j], currSum+arr1[j]);
        
        if (maxSum < currSum)
            maxSum = currSum;
    }
   
    return maxSum;
}

int main() 
{ 
   // int arr1[] = {1, 7, -10, 6, 2}; 
    //int arr2[] = {5, 6, 7, 1};
    int arr1[] = {-3, -4, -5, -4, -6}; 
    int arr2[] = {-1, -8, -5};
   
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    
    cout << maxSubArraySum(arr1, size1, arr2, size2)<<endl;   
    return 0; 
} 
