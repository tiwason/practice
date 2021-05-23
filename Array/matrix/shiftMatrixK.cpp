#include <iostream>

using namespace std;

#define R 4
#define C 4

void printMatrix(int arr[R][C])
{
    for(int i=0;i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<< arr[i][j] <<"   ";
        }
        cout<<endl;
    }
}

void reverse(int arr[], int size)
{
    int i=0, j=size-1;
    while(i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void shiftMatrix(int arr[R][C], int k)
{
    for(int i=0; i<R; i++)
    {
        reverse(arr[i], R);
        reverse(arr[i],k);
        reverse(arr[i]+k, C-k);
    }
}

int main() 
{ 
    
    int a[R][C] = { {1,  2,  3,  4}, 
                    {5,  6,  7,  8}, 
                    {9,  10, 11, 12}, 
                    {13, 14, 15, 16}  }; 
  
    /* int a[R][C] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9} 
                     }; */
     
    shiftMatrix(a, 2);
    printMatrix(a); 
    
    return 0; 
} 