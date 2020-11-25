#include <iostream>
#include <vector>

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

void segregate(vector<int>& vec)
{
   int i = 0;
   int j = vec.size() - 1;

   while(i < j)
   {
        if (vec[i] == 0)
            i++;
        if (vec[j] == 1)
            j--;
        
        if (vec[i] == 1 && vec[j] == 0)
        {
            vec[i] = 0;
            vec[j] = 1;
            i++; j--;
        }
   }
   printVector(vec);
}

int main()
{
    //vector<int> vec = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    vector<int> vec = {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1};

    segregate(vec);

    return 0;
}