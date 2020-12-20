#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printVector(vector<int>& vec)
{
    vector<int>::iterator it;
    for(it=vec.begin(); it!=vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<endl;
}

bool isIncreasing(vector<int>& vec)
{
    for(int i=1; i<vec.size(); i++)
    {
        if(vec[i] < vec[i-1])
            return false;
    }
    return true;
}

bool isDecreasing(vector<int>& vec)
{
    for(int i=1; i<vec.size(); i++)
    {
        if(vec[i] > vec[i-1])
            return false;
    }
    return true;
}

int shortestUnorderedArr(vector<int>& vec)
{
    if (isIncreasing(vec) || isDecreasing(vec))
        return 0;
    else
    {
        return 3;
    }
    
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    //vector<int> vec = {7, 9, 10, 8, 11};

    cout << shortestUnorderedArr(vec) << endl;

    return 0;
}