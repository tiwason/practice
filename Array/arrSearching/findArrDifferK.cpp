#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int search(int arr[], int size, int diff, int num)
{
    int start = 0;

    while(start != size)
    {
       if (arr[start] == num)
          return start;
       
        start = start + max(1, (abs(num - arr[start])/diff));
    }

 return -1;
}

int main() 
{ 
    //int arr[] = {20, 40, 50, 70, 70, 60}; 
    int arr[] = {4, 5, 6, 7, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout << search(arr, size, 1, 6)<<endl; 
  
    return 0; 
} 
