#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void printVector(vector<int>& vec)
{
    for(int i=0; i<vec.size(); i++)
        cout<<vec[i] <<" ";
    cout<<endl;
}

int mininimumJump(vector<int>& vec)
{ 
    int size = vec.size();
    int jumps = 0;
    
    if (vec[0] > 0)
    {
        int maxIndex = 0;
        int i = 0;
        jumps = 0;

        while(i<size)
        {   
            //range of jump starting from (i+1)th position
            int jumpStart = i+1;
            int jumpEnd = (i + vec[maxIndex] <= size) ? i+vec[maxIndex] : size-1;
            maxIndex = jumpStart;
            
            //last stretch containing end element
            if (jumpEnd == size-1)
            {
                jumps++; break;
            }

            //Traverse possible jump places
            for(int j=jumpStart; j <= jumpEnd; j++)
            {
                if (maxIndex + vec[maxIndex] <= vec[j]+j)
                    maxIndex = j;
            }
           
            i = maxIndex;
            jumps++;
        }
    }
    
    return jumps;
}

int main()
{
   
    //vector<int> vec = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    vector<int> vec = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << mininimumJump(vec) << endl;

    return 0;
}