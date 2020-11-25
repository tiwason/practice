#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


void smallestDiffTriplet(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    int size = arr1.size();

    int i=0, j=0, k=0;
    int resA, resB, resC;

    int minDiff = INT_MAX;

    for( ; i<size && j<size && k<size ;)
    {
        int maximum = max(arr1[i], max(arr2[j], arr3[k]));
        int minimum = min(arr1[i], min(arr2[j], arr3[k]));
        int diff = maximum - minimum;

        if (minDiff > diff) 
        {
            minDiff = diff;
            resA = arr1[i];
            resB = arr2[j];
            resC = arr3[k];
        }     
         if (minimum == arr1[i])
            i++;
        else if(minimum == arr2[j])
            j++;
        else
            k++;  
    }
    cout <<resA << " " << resB <<" "<<resC<<endl;
}

int main() 
{ 
   // vector<int> arr1 = {5, 2, 8};
   // vector<int> arr2 = {10, 7, 12};
   // vector<int> arr3 = {9, 14, 6};
      vector<int> arr1 = {15, 12, 18, 9};
      vector<int> arr2 = {10, 17, 13, 8};
      vector<int> arr3 = {14, 16, 11, 5};
       
    smallestDiffTriplet(arr1, arr2, arr3);
    
    return 0; 
} 
