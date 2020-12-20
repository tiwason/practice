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

void moveZeroesToEnd(vector<int> vec)
{
    int i = 0;

    while(i < vec.size())
    {
        if (vec[i] == 0)
        {
            int j = i;
            while(j < vec.size() && vec[j] == 0)
                j++;
            
            if (j == vec.size()) //no positive elem remaining
                break;
            
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
            i++;
    }
   
    printVector(vec);
}

int main()
{
    vector<int> vec = {1, 2, 0, 4, 3, 0, 5, 0};
    //vector<int> vec = {1, 2, 0, 0, 0, 3, 6};
  
    moveZeroesToEnd(vec);
    return 0;
}