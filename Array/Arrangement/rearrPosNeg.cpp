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
    int i = 0;

    while(i < vec.size())
    {
        if (i%2 ==0)
        {
            if (vec[i] < 0)
            {
                int j = i;
                while(j<vec.size())
                {
                    if(vec[j] > 0)
                        break;
                    else
                        j++;                    
                }
                if (j == vec.size())
                    break;
                
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }           
        }
        else {
            if (vec[i] > 0)
            {
                int j = i;
                while(j<vec.size())
                {
                    if(vec[j] < 0)
                        break;
                    else
                        j++;                    
                }
                 if (j == vec.size())
                    break;

                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
        i++;
    }

    printVector(vec);
}

int main()
{
    vector<int> vec = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
  
    rearrange(vec);
    return 0;
}