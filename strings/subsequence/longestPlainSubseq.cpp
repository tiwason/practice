#include <iostream>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
    int len = s.size();

    int dp[len][len] = {0};

    for (int i = 0; i < len; i++)
        dp[i][i] = 1;

    for (int cl = 2; cl <= len; cl++)
    {
        for (int i = 0; i < len - cl + 1; i++)
        {
            int j = i + cl - 1;

            if (s[i] == s[j] && cl == 2)
                dp[i][j] = 2;
            else if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][len - 1];
}

int main()
{
    string s = "geeksforgeeks";
    cout << longestPalindrome(s) << endl;
    return 0;
}