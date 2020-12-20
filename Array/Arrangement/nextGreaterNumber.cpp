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

void findNextNumber(vector<int>& vec)
{
    vector<int>::reverse_iterator rit = vec.rbegin();  
    vector<int>::reverse_iterator smallest = vec.rbegin();
    int next = *rit; rit++; 

    for(; rit != vec.rend(); rit++)
    {
        if (*rit < next)
            break;
        
        if (*smallest > *rit)
            smallest = rit;

        next = *rit;
    }

    if (rit != vec.rend())
    {
        int temp = *smallest;
        *smallest = *rit;
        *rit = temp;
        rit--;
        sort((rit+1).base(), vec.end());
    }
    else { //elements are sorted
        if (vec.front() < vec.back()) //increasing order
        {
            rit = vec.rbegin();rit++;
            int temp = *rit;
            *rit = vec.back();
            vec.back() = temp;
        }
        else //decreasing order
        {
            sort(vec.begin(), vec.end());
        }
    }
}

int main()
{
    //vector<int> vec = {2,1,8,7,6,5};
    //vector<int> vec = {1,2,3,4};
    vector<int> vec = {4,3,2,1};
    //vector<int> vec = {5,3,4,9,7,6};

    findNextNumber(vec);
    printVector(vec);
  
    return 0;
}