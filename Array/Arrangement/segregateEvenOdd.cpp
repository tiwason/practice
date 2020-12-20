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
    vector<int> vec = {1, 9, 5, 3, 2, 6, 7, 11};
    //vector<int> vec = {1, 3, 2, 4, 7, 6, 9, 10};

    sort(vec.begin(), vec.end(), [](const int a, const int b)
                                 { if ((a&1 && b&1) || (!(a&1) && !(b&1)))
                                        return false;
                    
                                 return (a&1 ? false : true);});
    printVector(vec);
  
    return 0;
}