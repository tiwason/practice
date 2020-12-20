#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
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

int main()
{
    //vector<int> vec = {10, 11, 12};
    //vector<int> indexes = {1, 0, 2};
    vector<int> vec = {50, 40, 70, 60, 90};
    vector<int> indexes = {3,  0,  4,  1,  2};

    unordered_map<int, int> hash;
    for (int i=0; i<vec.size(); i++)
    {
        hash[vec[i]] = indexes[i];
    }

    sort(vec.begin(), vec.end(), [&hash](const int a, const int b)
                                    { return (hash[a] < hash[b]);});
    printVector(vec);
  
    return 0;
}