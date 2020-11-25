#include <iostream>
#include <unordered_set>

using namespace std;

bool tripletSum(int arr[], int size, int sum)
{
    unordered_set<int> visibleSet;

    for (int i=0; i<size-2; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            int currSum = arr[i] + arr[j];
            if (visibleSet.find(sum-currSum) != visibleSet.end())
            {
                cout <<"Triplets are " << arr[i] << "," << arr[j]<<","
                        <<(sum-currSum) << endl;
                return true;
            }
            visibleSet.insert(arr[j]);
        }
    }

    return false;
}

int main() 
{ 
    //int arr[] = {12, 3, 4, 1, 6, 9}; 24
    int arr[] = {1, 2, 3, 4, 5};
       
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << tripletSum(arr, size, 9) <<endl;
    
    return 0; 
} 
