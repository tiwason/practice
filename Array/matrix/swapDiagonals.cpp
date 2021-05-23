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

void swapDiagonals(int arr[R][C])
{
    for(int i = 0; i< R; i++)
    {
        int temp = arr[i][i];
        arr[i][i] = arr[i][C-i-1];
        arr[i][C-i-1] = temp;
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
     
    swapDiagonals(a);
    printMatrix(a); 
    
    return 0; 
} 