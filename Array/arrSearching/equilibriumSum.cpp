#include <iostream>
#include <numeric>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int equalSum(int arr[], int size)
{
   int totalSum = accumulate(arr, arr+size, 0);
   int pre_sum=0;

   for(int i=0; i<size; i++)
   { 
       pre_sum += arr[i];
       if(pre_sum == (totalSum - pre_sum+arr[i]))
            return pre_sum;
   }

   return -1;
}

int main() 
{ 
    int arr[] = {-2, 5, 3, 1, 2, 6, -4, 2}; 
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << equalSum(arr, size)<<endl;   
    return 0; 
} 
