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

int findElem(int arr[], int start, int end, int elem)
{
    int mid = (start+end)/2;

    if (mid == end)
        return end;
    
    if(elem >arr[mid] && elem <=arr[mid+1])
        return mid;
    
    if (elem > arr[mid])
        return findElem(arr, mid+1, end, elem);
    else
    {
        return findElem(arr, start, mid-1, elem);
    }      
}

int findSubsets(int arr[], int size, int prod)
{
    sort(arr, arr+size);
    if (arr[0] > prod)
        return 0;

    int index = findElem(arr, 0, size-1, prod);
    int subsets = index + 1;

    for (int i=index; i>0; i--)
    {
        if(arr[i]*arr[i])
    }

    return subsets;
}

int main() 
{ 
   //int arr[] = {12, 32, 21}; //1
   int arr[] = {2, 4, 5, 3}; //12
   //int arr[] = {4, 2, 3, 6, 5}; //25
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << findSubsets(arr, size, 12) << endl;
    
    return 0; 
} 
