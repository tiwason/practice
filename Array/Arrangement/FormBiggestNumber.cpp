#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <string>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

bool compare(const int a, const int b)
{   
    string str1 = to_string(a);
    string str2 = to_string(b);

    return ((str1+str2 > str2+str1) ? true: false);
}

int main()
{
    //vector<int> vec = {54, 546, 548, 60};
    vector<int> vec = {1, 34, 3, 98, 9, 76, 41, 4};

    sort(vec.begin(), vec.end(), compare);
    printVector(vec);
  
    return 0;
}