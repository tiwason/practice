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

void rearrange(vector<int>& vec)
{
    for(int i=1; i<vec.size(); i++)
    { 
        if (!(i&1) && vec[i] > vec[i-1])
        {
            int temp = vec[i];
            vec[i] = vec[i-1];
            vec[i-1] = temp;
        }
        else if(i&1 && vec[i] < vec[i-1] )
        { 
            int temp = vec[i];
            vec[i] = vec[i-1];
            vec[i-1] = temp;
        }
    }    
}

int main()
{
    vector<int> vec = {1, 2, 2, 1};
    //vector<int> vec = {1, 3, 2, 2, 5};

    rearrange(vec);
    printVector(vec);
  
    return 0;
}