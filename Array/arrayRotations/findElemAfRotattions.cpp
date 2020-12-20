#include <iostream>
using namespace std;

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
void rotate(int arr[], int d, int end, int start)
{
    reverse(arr, start, end);
    reverse(arr, start, d-1);
    reverse(arr, d, end);
}
void printArray(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
       cout << arr[i] << " ";
    cout <<endl;
}

int findElement(int arr[], int ranges[][2], int rotations, int index)
{
    for (int i=0; i<rotations; i++)
    {
        int start = ranges[i][0];
        int end = ranges[i][1];
 
        rotate(arr, 1, end, start);

        printArray(arr, end+1);
    }

    return  arr[index];
}


int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5 }; 
    int rotations = 2; 
  
    int ranges[rotations][2] = { { 0, 2 }, { 0, 3 } }; 
  
    int index = 1; 
  
    cout << findElement(arr, ranges, rotations, index); 
  
    return 0; 
  
} 
