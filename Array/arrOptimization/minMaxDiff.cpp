#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int mininimizeMaxDiff(vector<int>& vec, int k)
{ 
    sort(vec.begin(), vec.end());

    int size = vec.size();
    int minm = vec[0]+k;
    int max = vec[size-1]-k;

    if (minm > max)
    {
        int temp = minm;
        minm = max;
        max = temp;
    }
    int minMaxDiff = vec[size-1] - vec[0];

    for(int i=1; i<size-1; i++)
    {
        int sub = vec[i] - k;
        int add = vec[i] + k;

        //cout << vec[i] <<" "<< sub <<" "<<add <<endl;

        if (sub >= minm || add <= max) // new value has no impact to max/min
            continue;
        
        if (max-sub > add-minm)
            max = add;
        else
            minm = sub;
    }
    return min(minMaxDiff, max-minm);   
}

int main()
{
    //vector<int> vec = {1, 15, 10}; //6
    //vector<int> vec = {1, 5, 15, 10};//3
    //vector<int> vec = {4, 6};//10
    //vector<int> vec = {6, 10};//3
    //vector<int> vec = {1, 10, 14, 14, 14, 15};//6
    vector<int> vec = {1, 2, 3}; //2
  
    int k=2;
    cout << mininimizeMaxDiff(vec ,k) << endl;

    return 0;
}