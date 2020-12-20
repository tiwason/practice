#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int findPivot(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    int pivot = -1;
    
    while (start <= end)
    { 
        int mid = (start+end)/2;
        int i = (mid+1)%size;
        int j = (mid-1)%size;
        
        if((arr[i] > arr[mid]) && (arr[mid] < arr[j]) )
        {
            pivot = mid;
            break;
        }
        else if (arr[mid] < arr[end])
            end = mid-1;
        else
            start = mid +1;          
    }
    return pivot;
}

bool findPairSum(int arr[], int size, int num)
{
    int pivot = findPivot(arr, size);
    if (pivot != -1)
    {
       int start = pivot;
       int end = (pivot - 1)%size;

       while (start != end)
       {
           int tmpSum = arr[start] + arr[end];
        
           if ( tmpSum == num)
              return true;
           else if(tmpSum > num)
              end = (size + end-1)%size;
           else
              start = (start+1)%size;
       }
    }
    
    return false;
}

int main()
{
    int arr[] = {11, 15, 26, 38, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    bool res = findPairSum(arr, size, 45);
    cout << "Found Pair with given sum : "<< res << endl;
    //printArray(arr, size);

    return 0;
}