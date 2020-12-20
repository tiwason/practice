#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int countTriangles(vector<int>& vec)
{
    sort(vec.begin(), vec.end());
    int count = 0;

    for(int i = vec.size()-1; i>1; i--)
    {
        int left = 0, right = i-1;
        while(left < right)
        {
            if(vec[left] + vec[right] > vec[i])
            {
                count += right - left;
                right--;
            }
            else
                left++;
        }
    }

    return count;
}

int main()
{
    //vector<int> vec = {4, 6, 3, 7};
    vector<int> vec = {10, 21, 22, 100, 101, 200, 300};

    cout << countTriangles(vec) << endl;

    return 0;
}