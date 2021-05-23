#include <iostream>
#include <string>

using namespace std;

// recursive solution
int countStrings(string s1, string s2, int i1, int i2)
{
    if (i2 == s2.size())
        return 1;

    if (i1 == s1.size())
        return 0;

    if (s1[i1] == s2[i2])
        return (countStrings(s1, s2, i1 + 1, i2 + 1) + countStrings(s1, s2, i1 + 1, i2));

    else
        return countStrings(s1, s2, i1 + 1, i2);
}

//dp
int countStrings(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();

    int dp[m + 1][n + 1];

    //if s1 is empty
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    //if s2 is empty
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //inlude exclude
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}