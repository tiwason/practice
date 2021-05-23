#include <iostream>

using namespace std;

bool subsetSum(int arr[], int sum, int size)
{
    bool s[size+1][sum+1]; //elements and sum

    for (int i=0; i<=size; i++)
        s[i][0] = true;

    for (int i=1; i<=sum; i++)
        s[0][i] = false;
    
    for (int i=1; i<= size; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            if (arr[i-1] > j)
                s[i][j] = s[i-1][j];
            else
                s[i][j] = s[i-1][j] || s[i-1][j-arr[i-1]];
        }
    }
    return s[size][sum];
}

int main()
{
    int arr[] = {3,4,5,2};
    int sum = 13;
    int size = sizeof(arr)/sizeof(arr[0]);

    if (subsetSum(arr, sum, size))
        cout << "TRUE !!" << endl;
    else
        cout << "False !!" << endl;
}