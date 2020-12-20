#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

void findElements(const vector<int>& vec)
{
    int first = INT_MIN;
    int second = INT_MIN;

    for(const auto &e : vec)
    {
        if (e > first)
        {
            second = first;
            first = e;
        }
        else if (e > second)
        {
            second = e;
        }
    }
    for(const auto &e : vec)
    {
        if (e <second)
            cout << e <<" ";
    }
    cout <<endl;
}

int main()
{
    //vector<int> vec = {2, 8, 7, 1, 5};
    vector<int> vec = {7, -2, 3, 4, 9, -1};
   
    findElements(vec);
    return 0;
}