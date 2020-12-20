#include <iostream>

using namespace std;

#define R 3
#define C 3

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
void rotate90Matrix (int m, int n, int arr[R][C])
{
   for (int i = 0; i<n/2; i++)
   {
       for (int j=i; j<n-i-1; j++)
       {
           int temp = arr[i][j];
           arr[i][j] = arr[j][n-i-1];
           arr[j][n-i-1] = arr[n-i-1][n-j-1];
           arr[n-i-1][n-j-1] = arr[n-j-1][i];
           arr[n-j-1][i] = temp;
       }
   }
}

int main() 
{ 
    
    /*int a[R][C] = { {1,  2,  3,  4}, 
        {5,  6,  7,  8}, 
        {9,  10, 11, 12}, 
        {13, 14, 15, 16}  };*/
  
    int a[R][C] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9} 
                     };
     
    rotate90Matrix(R, C, a);
    printMatrix(a);
    return 0; 
} 