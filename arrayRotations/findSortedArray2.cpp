#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

//use property to find sorted half and discard other half
int binarySearch(int arr[], int start, int end, int num)
{
    int mid = start + (end-start)/2; // handle  overflow
    if (arr[mid] == num)
        return mid;
    

    if(start < end)
    {
        if (arr[start] < arr[end]){ //array is sorted not rotated
            if (arr[mid] > num)
               binarySearch(arr, mid+1, end, num);
            else
               binarySearch(arr, start, mid-1, num);            
        }
        else //array is sorted and rotated
        {
          if (arr[mid] < arr[end]) //right half is sorted
          {
              if (num > arr[mid])
              {
                if (num < arr[start])
                  binarySearch(arr, mid+1, end, num);
                else
                  binarySearch(arr, start, mid-1, num);
              }
              else {
                  binarySearch(arr, start, mid-1, num);
              }
          }
          else //left half is sorted
          {
              if (num < arr[mid])
              {
                if (num > arr[start])
                  binarySearch(arr, start, mid-1, num);
                else
                  binarySearch(arr, mid+1, end, num);
              }
              else {
                  binarySearch(arr, mid+1, end, num);
              }
          }          
        }
    }

    return -1;
}

int main()
{
    int arr[] = {6,7,8,9,10,11,12,1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int res = binarySearch(arr, 0, size-1, 1);
    cout <<"Key is found at index : "<< res << endl;
    //printArray(arr, size);

    return 0;
}