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

void rotate(int arr[], int d, int n)
{
    if(d == 0 || d > n)
      return;
    
    int blockSize = gcd (n, d);
    int blocks = (n/blockSize);
    int numberOfRotations = d/blockSize;

    for (int i=0; i<numberOfRotations; i++)
    {
        for(int j=0; j<blockSize; j++)
        {
            int k = j;
            int tmp = arr[k];

            for(int a = 0; a<(blocks-1); a++)
            {   
                arr[k] = arr[k+blockSize];
                k = k + blockSize;
            }
            arr[k] = tmp;
           // printArray(arr, n);
           // cout << endl;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    rotate(arr, 2, size);
    cout <<"Rotated array is : " << endl;
    printArray(arr, size);

    return 0;
}