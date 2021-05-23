#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

int maxSumSubsequence(vector<int>& vec)
{
    int inclSum=0, exclSum=0, currSum=0;

    for(const auto& e: vec)
    {
        int temp = exclSum;
        exclSum = max(inclSum, exclSum);
        inclSum = temp + e;
    }
    return max(inclSum, exclSum);
}

int main()
{
    vector<int> vec = {5, 5, 10, 100, 10, 5}; //110
    //vector<int> vec = {1, 2, 3}; //4
    //vector<int> vec = {1, 20, 3}; //20

    cout << maxSumSubsequence(vec) <<endl;
    return 0;
}