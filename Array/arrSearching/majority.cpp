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

int majority(int arr[], int size)
{
    int count = 0;
    int majority = arr[0]; 

    for (int i=0; i<size; i++)
    {
        if(arr[i] == majority)
            count++;
        else
            count--;
        
        if(count == 0)
        {
            majority = arr[i];
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i<size; i++)
    {
        if (arr[i] == majority)
            count++;
    }

    if(count > (size/2))
        return majority;

    return -1;
}

int main() 
{ 
    //int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4}; 
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4};
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    int result = majority(arr, size);
    (result == -1) ? cout<<"No majority" : cout<<result;
    cout<<endl;
    return 0; 
} 
