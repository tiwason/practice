#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>

using namespace std;

const int alphaSize = 256;

//substring should have all characters from pattern.
string findSubString(string str, string pattern)
{
    unordered_map<char, int> hash_pat, hash_str;

    for (auto &c : pattern)
        hash_pat[c]++;

    int start = 0, count = 0, min_len = INT_MAX, start_index = -1;

    for (int i = 0; i < str.size(); i++)
    {
        hash_str[str[i]]++;

        if (hash_str[str[i]] <= hash_pat[str[i]])
            count++;

        if (count == pattern.size())
        {
            while (hash_pat[str[start]] == 0 || hash_str[str[start]] > hash_pat[str[start]])
            {
                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }

            int len = i - start + 1;
            if (min_len > len)
            {
                min_len = len;
                start_index = start;
            }
        }
    }
    return (str.substr(start_index, min_len));
}

int main()
{
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : \n"
         << findSubString(str, pat) << endl;
    return 0;
}