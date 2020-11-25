#include <iostream>
#include <unordered_set>

using namespace std;

bool zeroSumTriplet(int arr[], int size)
{
    bool result = false;

    for (int i=0; i<size-2; i++)
    {
        unordered_set<int> visibleSet;
        for(int j=i+1; j<size; j++)
        {
            int currSum = arr[i] + arr[j];
            
            if (visibleSet.find(0-currSum) != visibleSet.end())
            {
                cout <<"Triplets are " << arr[i] << "," << arr[j]<<","
                        <<(0-currSum) << endl;
                result = true;
            }
            visibleSet.insert(arr[j]);
        }
    }

    return result;
}

int main() 
{ 
    //int arr[] = {0, -1, 2, -3, 1};
    int arr[] = {1, -2, 1, 0, 5};
       
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << zeroSumTriplet(arr, size) <<endl;
    
    return 0; 
} 
