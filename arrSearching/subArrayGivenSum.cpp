#include <iostream>

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

    for (int i=0;i<size;i++)
    {
        tmpSum+= arr[i];
        end=i;

        while(tmpSum > sum && start < i-1)
        {
            tmpSum -= arr[start];
            start++;
        }
        cout <<tmpSum <<" "<<start<<" "<<end<<endl;
         if(tmpSum == sum)
        {
            cout << start <<" " <<end <<endl;
            return;
        }

    }

    cout<<"Not found"<<endl;
}

int main() 
{ 
    //int arr[] = {1, 4, 0, 0, 3, 10, 5}; 7
    int arr[] = {1, 4}; 
    //int arr[] = {1, 4, 20, 3, 10, 5};
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    findSubArray(arr, size, 0);
    
    return 0; 
} 
