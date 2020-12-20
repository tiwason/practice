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

void replaceElem(vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    
    int previous = vec[0];
    int next;

    for (int i=0; i< vec.size(); i++)
    {
        next = (i == vec.size()-1) ? vec[i] : vec[i+1];
        int temp = vec[i];
        vec[i] = previous * next;
        previous = temp;
    }
}

int main()
{
    vector<int> vec = {2, 3, 4, 5, 6};
    replaceElem(vec);
    printVector(vec);
  
    return 0;
}