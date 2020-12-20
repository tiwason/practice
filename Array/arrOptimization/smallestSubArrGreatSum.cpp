#include <iostream>
#include <climits>

using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

void findSubArray(int arr[], int size, int sum)
{
    int tmpSum = 0;
    int start = 0;
    int end = 0;
    int minSize = INT_MAX;

    for (int i=0;i<size;i++)
    {
        tmpSum+= arr[i];
        end=i;

        while(tmpSum > sum && start <= i)
        {
            minSize = min(minSize, (end-start+1));
            tmpSum -= arr[start];
            start++;            
        }    
    }

    cout<<minSize<<endl;
}

int main() 
{ 
    //int arr[] = {1, 4, 45, 6, 0, 19}; // 51
    //int arr[] = {1, 10, 5, 2, 7}; //9
    //int arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};//280
    int arr[] = {1, 2, 4};//10
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    findSubArray(arr, size, 8);
    
    return 0; 
} 
