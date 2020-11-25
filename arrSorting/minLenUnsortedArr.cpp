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

int binarySearch(vector<int>& vec, int start, int end, int num)
{
    int mid = (end - start)/2;

    while(start <= end)
    {
        if(num > vec[mid] && num < vec[mid+1])
            return mid;
        else if (num < vec[mid] && num > vec[mid-1])
            return mid;
        
        
    }
    return -1;
}

void minLenUnsortedArr(vector<int>& vec)
{
    if (isIncreasing(vec) || isDecreasing(vec))
        return;
    
    int start = 0, end = 0;
    int max = vec[0]; int maxIndex = 0;

    for(int i=1; i<vec.size(); i++)
    {
        if (max < vec[i])
        {
            max = vec[i];
            maxIndex = i;
        }
        else
        {
            start = binarySearch(vec, 0, i, vec[i]);
            cout << start << endl; break;
        }
        
    }
   
}

int main()
{
    vector<int> vec = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    //vector<int> vec = {0, 1, 15, 25, 6, 7, 30, 40, 50};

    minLenUnsortedArr(vec);

    return 0;
}