#include <iostream>
using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
} 

void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }    
}

void rotate(int arr[], int d, int n)
{
    reverse(arr, 0, n-1);
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    rotate(arr, 3, size);
    cout <<"Right Rotated array is : " << endl;
    printArray(arr, size);

    return 0;
}