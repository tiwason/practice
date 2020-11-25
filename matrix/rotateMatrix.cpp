#include <iostream>

#define R 4
#define C 4

void rotateMatrix (int m, int n, int arr[R][C])
{
    for(int i=0; i<m ;i++)
    {
        
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
                     }; 
     */ 
    rotateMatrix(R, C, a); 
    return 0; 
} 