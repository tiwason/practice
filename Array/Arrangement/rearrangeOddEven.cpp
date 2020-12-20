#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void printVector(vector<int>& vec)
{
    for(const auto &elem: vec)
    {
        cout << elem <<" ";
    }
    cout<< endl;
}

void rearrange(vector<int> vec)
{
    vector<int> vecTemp = vec;

    sort(vecTemp.begin(), vecTemp.end());

    int size = vec.size();
    int i = 0;
    int j = (size - floor(size/2))-1;

    while(i < size) //fill odd positions
    {
        vec[i] = vecTemp[j];
        j--;
        i += 2; 
    }
 
    j = (size - floor(size/2)); i = 1;
    while(i < size) //fill even positions
    {
        vec[i] = vecTemp[j];
        j++;
        i += 2;
    }
    printVector(vec);
}

int main()
{
    //vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    vector<int> vec = {1, 2, 1, 4, 5, 6, 8, 8};
  
    rearrange(vec);
    return 0;
}