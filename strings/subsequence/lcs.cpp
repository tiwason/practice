#include <iostream>
#include <string>

using namespace std;

int findLCS(string s1, string s2)
{
    int l1 = s1.size();
    int l2 = s2.size();

    int dp[l1 + 1][l2 + 1] = {0}; //initilialize

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[l1][l2];
}

int main()
{
    //string s1 = "ABCDGH", s2 = "AEDFHR";
    string s1 = "AGGTAB", s2 = "GXTXAYB";

    cout
        << "length of lcs is: " << findLCS(s1, s2) << endl;
    return 0;
}