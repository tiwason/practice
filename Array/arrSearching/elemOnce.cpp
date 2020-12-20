#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int search(int arr[], int size)
{
    int res =0;
    for (int i=0; i<size; i++)
    {
        res = res ^ arr[i];
    }
   return res;
}

int main() 
{ 
    int arr[] = {7, 3, 5, 4, 5, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << search(arr, size)<<endl; 
  
    return 0; 
} 
