#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef std::vector<int>::iterator vecIt;

vecIt* maxIt(vecIt a, vecIt b)
{
    return (*a > *b) ? &a : &b;
}

vecIt* minIt(vecIt a, vecIt b)
{
    return (*a < *b) ? &a : &b;
}

void smallestDiffTriplet(vector<int> arr1, vector<int> arr2, vector<int> arr3)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end());

    int resA, resB, resC;
    int minDiff = INT_MAX;

    vecIt it1 = arr1.begin();
    vecIt it2 = arr2.begin();
    vecIt it3 = arr3.begin();
    for( ; it1!=arr1.end() && it2!=arr2.end() && it3!=arr3.end() ;)
    {
        vecIt* itmax = maxIt(it1, *maxIt(it2, it3));
        vecIt* itmin = minIt(it1, *minIt(it2, it3));
        int diff = **itmax - **itmin;

        if (minDiff > diff) 
        {
            minDiff = diff;
            resA = *it1;
            resB = *it2;
            resC = *it3;
        }     
        ++(*itmin);
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
