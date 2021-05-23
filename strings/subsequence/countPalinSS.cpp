#include <iostream>
#include <string>

using namespace std;
const int len = 4;

int countPalinSS(const string &str, int dp[][len], int i, int j)
{
    if (i > j)
        return 0;

    if (i == j)
        return dp[i][j] = 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == str[j])
        return dp[i][j] = 1 + countPalinSS(str, dp, i + 1, j) + countPalinSS(str, dp, i, j - 1);
    else
        return dp[i][j] = countPalinSS(str, dp, i + 1, j) + countPalinSS(str, dp, i, j - 1) - countPalinSS(str, dp, i + 1, j - 1);
}

int main()
{
    string str = "abcb";
    // int len = str.size();

    int dp[len][len] = {-1};
    cout << countPalinSS(str, dp, 0, len - 1) << endl;
    return 0;
}