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

void findLeaders(int arr[], int size)
{
    int max = INT32_MIN;
    for (int j = size-1; j>=0; j--)
    {
        if (arr[j] > max)
        {
            cout << arr[j] <<" ";
            max = arr[j];
        }            
    }
   cout<<endl;
}

int main() 
{ 
    int arr[] = {16, 17, 4, 3, 5, 2}; 
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    findLeaders(arr, size);
    return 0; 
} 
