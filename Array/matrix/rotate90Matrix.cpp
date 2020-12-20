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
void rotate90Matrix (int m, int n, int arr[R][C])
{
   int rowStart = 0;
   int rowEnd = m-1;
   int colStart = 0;
   int colEnd = n-1;


   while( rowStart < rowEnd && colStart < colEnd)
   { 
       int rotate = rowEnd-rowStart;
       while(rotate--){
        int i = rowStart, j = colStart;
        while (j <= colEnd)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[rowStart][colStart];               
            arr[rowStart][colStart]  = temp;
            j++;
        }

        i++;
        j = colEnd;

        while (i <= rowEnd)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[rowStart][colStart];               
            arr[rowStart][colStart]  = temp;
            i++;
        }

        i = rowEnd;
        j--;

        while (j >= colStart)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[rowStart][colStart];               
            arr[rowStart][colStart]  = temp;
            j--;
        }

        i--;
        j = colStart;

        while (i >= rowStart)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[rowStart][colStart];               
            arr[rowStart][colStart]  = temp;
            i--;
        }
       }
        rowStart++; rowEnd--;
        colStart++; colEnd--;
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
     
    rotate90Matrix(R, C, a);
    printMatrix(a);
    return 0; 
} 