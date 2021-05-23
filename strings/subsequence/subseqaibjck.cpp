#include <iostream>
#include <string>

using namespace std;

int countSubsequences(string s)
{
    int aCount = 0, bCount = 0, cCount = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            aCount = 2 * aCount + 1;
        else if (s[i] == 'b')
            bCount = 2 * bCount + aCount;
        else
            cCount = 2 * cCount + bCount;
    }

    return cCount;
}

int main()
{
    string s = "abbc";
    cout << countSubsequences(s) << endl;
    return 0;
}