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

int minSteps(int arr[], int size)
{
    int minSteps = 0;
    int zero_count = 0;

    while(zero_count < size)
    {   
        bool incr = false;
        for(int i=0; i<size; i++)
        {   
            if (arr[i] != 0)
            {
                int rem = arr[i]%2;
                arr[i] -= rem;
                minSteps += rem;

                if (arr[i] == 0)
                    zero_count++;
                
                arr[i] = arr[i]/2;
                if (arr[i] > 0)
                    incr = true;
            }
        }
        incr ? minSteps++ : minSteps;
    }
    return minSteps;
}

int main() 
{ 
    //int arr[] = {2, 3};
   //int arr[] = {2, 1};
   //int arr[] = {16, 16, 16};
   int arr[] = {1, 1, 1};
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << minSteps(arr, size) << endl;
    
    return 0; 
} 
