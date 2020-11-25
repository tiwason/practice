#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortAlternate(vector<int>& vec)
{
    sort(vec.begin(), vec.end());

    int i=0, j=vec.size()-1;
    while(i <= j)
    {
        cout << vec[j] <<" ";
        if (i!=j)
            cout<< vec[i] << " ";
        
        i++; j--;
    }
    cout<<endl;
}

int main()
{
    //vector<int> vec = {7, 1, 2, 3, 4, 5, 6};
    vector<int> vec = {1, 6, 9, 4, 3, 7, 8, 2};

    sortAlternate(vec);

    return 0;
}