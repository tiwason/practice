#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minDistance(vector<int>& vec, int a, int b)
{ 
    int posA = -1;
    int posB = -1;
    int minDist = INT_MAX;

    for(int i=0; i<vec.size(); i++)
    {
        if (vec[i] == a)
            posA = i;
        else if (vec[i] == b)
            posB = i;

        if(posA!=-1 && posB!=-1)
        {
            if (abs(posA-posB) == 1)
            {   
                minDist=1;
                break;
            }
        
            if(minDist > abs(posA-posB))
            minDist = abs(posA-posB);
        }
    }

    return minDist;
}

int main()
{
    //vector<int> vec = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};//3 6
    vector<int> vec = {2, 5, 3, 5, 4, 4, 2, 3};//3 2
  
    cout << minDistance(vec ,3, 2) << endl;

    return 0;
}