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

void printSpiral(int arr[R][C])
{
    int rowStart = 0;
    int rowEnd = R-1;
    int colStart = 0;
    int colEnd = C-1;

   while( rowStart < rowEnd && colStart < colEnd)
    {
        int i = rowStart, j = colStart;
        while (j <= colEnd)
        {
            cout << arr[i][j] << " ";
            j++;
        }

        j = colEnd;
        i++;

        while(i <= rowEnd)
        {
            cout << arr[i][j] << " ";
            i++;
        }

        i = rowEnd;
        j--;
        while (j>= colStart)
        {
            cout << arr[i][j] << " ";
            j--;
        }

        j = colStart;
        i--;

        while (i > rowStart)
        {
            cout << arr[i][j] << " ";
            i--;
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
     
    printSpiral(a); cout <<endl;
    
    return 0; 
} 