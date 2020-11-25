#include <iostream>
#include <unordered_map>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

bool findPair(int arr[], int size, int sum)
{
    if(size>1)
    {
        unordered_map<int, int> available;

        for(int i=0; i<size; i++)
            available[arr[i]] = i;
        
        for(int i=0; i<size; i++)
        {
            int chkValue = sum - arr[i];
            if(available.find(chkValue) != available.end() 
                && available[chkValue] != i)
                return true;
        }
    }
    return false;
}

int main() 
{ 
    int arr[] = {0, -1, 2, -3, 1}; 
   // int arr[] = {1, -2, 1, 0, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum= 0;
  
    cout << findPair(arr, size, sum)<<endl; 
  
    return 0; 
} 
