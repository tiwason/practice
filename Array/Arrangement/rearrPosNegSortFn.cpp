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

bool compare(const int a, const int b)
{   cout <<a<<" " <<b<<endl;
    if ((a > 0 && b > 0) || (a < 0 && b < 0) || (a > 0 && b < 0))
        return false;
    
    if (a < 0 && b > 0)
        return true;
    
    if((a == 0 && b < 0) || (a > 0 && b == 0))
        return true;
 
    if((a == 0 && b > 0) || (a < 0 && b == 0))
        return false;
}

int main()
{
    vector<int> vec = {12, 11, -13, -5, 5, -7, 6, -3, -6};
    //vector<int> vec = {-12, 11, 0, -5, 6, -7, 5, -3, -6};

    sort(vec.begin(), vec.end(), compare);
    printVector(vec);
  
    return 0;
}