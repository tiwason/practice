#include <iostream>
#include <vector>

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
    int j = 0;
    while(j < vec.size())
    { 
        if (vec[j] == -1)
        {   j++;
            continue;
        }

        if (vec[j] != j)
        {
            int temp = vec[vec[j]];
            vec[vec[j]] = vec[j];
            vec[j] = temp;
        }
        
        if(vec[j] == j)
            j++;
    }
    
    printVector(vec);
}

int main()
{
    //vector<int> vec = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vector<int> vec = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
                     11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
  
    rearrange(vec);
    return 0;
}