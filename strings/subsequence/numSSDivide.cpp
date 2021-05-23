#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int countDivisibleSubseq(string s, int n)
{
    int len = s.size();
    int dp[len][n];
    memset(dp, 0, sizeof(dp));

    dp[0][(s[0] - '0') % n]++;

    for (int i = 1; i < len; i++)
    {
        dp[0][(s[i] - '0') % n]++; //start a new sequence here

        for (int j = 0; j < n; j++)
        {
            //excluding ith index
            dp[i][j] += dp[i - 1][j];

            //including ith index
            dp[i][(j * 10 + (s[i] - '0')) % n] += dp[i - 1][j];
        }
    }

    return dp[len - 1][0];
}

int main()
{
    string str = "1234";
    int n = 4;
    cout << countDivisibleSubseq(str, n) << endl;
    return 0;
}