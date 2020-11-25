#include <iostream>
using namespace std;


int rotationCount(int arr[], int size)
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

int main()
{
    //int arr[] = {15, 18, 2, 3, 6, 12};
    //int arr[] = {7, 9, 11, 12, 5};
    int arr[] = {7, 9, 11, 12, 15};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = rotationCount(arr, size);
    cout << "Number of Rotations in Given array : "<< res << endl;
    //printArray(arr, size);

    return 0;
}