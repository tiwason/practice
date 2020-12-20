#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int findMerges(int arr[], int size)
{
    if (size == 1)
        return 0;
    
    int start = 0;
    int end = size-1;
    int merge = 0;

    while(start < end)
    {
        if (arr[start] == arr[end])
        {
            start++;
            end--;
        }
        else if(arr[start] < arr[end])
        {
            arr[start+1] = arr[start] + arr[start+1];
            start++;
            merge++;
        }
        else
        {
           arr[end-1] = arr[end] + arr[end-1];
           end--;
           merge++;
        }
    }    
    return merge;
}

int main() 
{ 
   //int arr[] = {15, 4, 15}; //0
   //int arr[] = {1, 4, 5, 1}; //1
   int arr[] = {11, 14, 15, 99}; //3
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << findMerges(arr, size) << endl;
    
    return 0; 
} 
