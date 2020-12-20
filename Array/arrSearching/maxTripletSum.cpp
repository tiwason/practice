#include <iostream>
#include <map>
#include <numeric>

using namespace std;

int findSum(map<int, int>& triplet)
{
    map<int, int>::iterator it;
    int sum=0;
    for (it = triplet.begin(); it!=triplet.end(); it++)
        sum+=it->first;
    return sum;
}

int maxTripletSum(int arr[], int size)
{
    map<int,int> triplet; //value, index
    triplet[arr[0]] = 0;
    triplet[arr[1]] = 1;
    triplet[arr[2]] = 2;

    for(int i=3; i<size; i++)
    {
        int minInTriplet = triplet.begin()->first;
        if (arr[i] > minInTriplet)
        {
            triplet.erase(triplet.begin());
            triplet[arr[i]] = i;
        }
    }
    return findSum(triplet);
}

int main() 
{ 
    //int arr[] = {1, 2, 3, 0, -1, 8, 10};
    //int arr[] = {9, 8, 20, 3, 4, -1, 0};
    int arr[] = {1, 0, 8, 6, 4, 2};
   
    int size = sizeof(arr)/sizeof(arr[0]);    
    cout << maxTripletSum(arr, size) <<endl;
    
    return 0; 
} 
