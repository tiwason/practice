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

void printLowerTriangle(int arr[R][C])
{
    for (int i=0; i<R; i++)
    {
        int  j = 0;
        for(; j <= i; j++)
        {
            cout << arr[i][j] << " ";
        }

        while(j < C)
        {
            cout << "0" << " ";
            j++;
        }

        cout << endl;
    }
}

void printUpperTriangle(int arr[R][C])
{
    for (int i=0; i<R; i++)
    {
        int  j = 0;

        while(j < i)
        {
            cout << "0" << " ";
            j++;
        }

        for(; j < C; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

int main() 
{ 
    
    /*int a[R][C] = { {1,  2,  3,  4}, 
        {5,  6,  7,  8}, 
        {9,  10, 11, 12}, 
        {13, 14, 15, 16}  }; */
  
     int a[R][C] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                      {7, 8, 9} 
                     }; 
     
    printLowerTriangle(a); cout <<endl;
    printUpperTriangle(a);
    return 0; 
} 