#include <iostream>
#include <string>

using namespace std;

#define R 3
#define C 3

bool chkMatrixRows(int arr[R][C])
{
    string str;

    for(int i=0; i<C; i++)
        str += to_string(arr[0][i]);
    
    str += str;

    for (int i=1; i<R; i++)
    {   string temp;
        for (int j=0; j<C; j++)
        {
            temp += to_string(arr[i][j]);
        }
        if (str.find(temp) == string::npos)
            return false;
    }
    return true;
}

int main() 
{ 
    
    int a[R][C] = { {1,  2,  3}, 
        {3, 1, 2}, 
        {2, 3, 1} };
  
    /*int a[R][C] = {{1, 2, 3}, 
                      {3, 2, 1}, 
                      {1, 3, 2} 
                     };*/
     
    cout << chkMatrixRows(a)<< endl;
    
    return 0; 
} 