#include <iostream>

using namespace std;

int findSmallestNumber(int arr[], int size)
{
    int num=1;
    for (int i=0; i<size; i++)
    {
        if (num - arr[i] >= 0)
            num = num+arr[i];
        else
            return num;        
    }
    return num;
}

int main()
{
    //int arr[] = {1, 3, 6, 10, 11, 15}; //2
    //int arr[] = {1, 1, 1, 1}; //5
    //int arr[] = {1, 1, 3, 4}; //10
    //int arr[] = {1, 2, 5, 10, 20, 40}; //4
    int arr[] = {1, 2, 3, 4, 5, 6}; //22

    int size = sizeof(arr)/sizeof(arr[0]);

    cout << findSmallestNumber(arr, size) <<endl;
    return 0;
}