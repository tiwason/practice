#include <iostream>
#include <vector>
#include <map>

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

void sortAbsDiff(vector<int>& vec, int num)
{
    multimap<int, int> diffMap; //map of<difference, index>
    multimap<int, int>::iterator it;

    for(int i=0; i<vec.size(); i++)
        diffMap.insert({abs(vec[i] - num), vec[i]});
    
    int i=0;
    for (it=diffMap.begin(); it!=diffMap.end(); it++,i++)
        vec[i] = it->second;
   
    printVector(vec);
}

int main()
{
    //vector<int> vec = {10, 5, 3, 9, 2}; 7
    //vector<int> vec = {1, 2, 3, 4, 5}; 6
    vector<int> vec = {2, 6, 8, 3}; //5

    int k = 5;

    sortAbsDiff(vec, k);

    return 0;
}