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

void maxAvgSubArray(int arr[], int size, int k)
{
    int maxAvg = INT_MIN;
    int currAvg = 0;
    int i;

    for (i=0;i<k;i++)
        currAvg += arr[i];

    int end = k-1;
            
    while( i<size )
    {
        if (maxAvg < currAvg)
        {
            maxAvg = currAvg;
            end = i-1;
        }
        
        currAvg += arr[i];
        currAvg -= arr[i-k];
        i++;           
    }    

    cout <<maxAvg << " "<< end+1-k <<" "<<end<<endl;    
}

int main() 
{ 
    int arr[] = {1, 12, -5, -6, 50, 3};//4
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    maxAvgSubArray(arr, size, 4);
    
    return 0; 
} 
