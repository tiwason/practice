#include <iostream>
#include <queue>

using namespace std;

struct key
{
    int freq;
    char c;

    bool operator < (const key& p2) const
    {
        return freq<p2.freq;
    }
};

void rearrange (string s1, string s2)
{
    int count[26];
    for (auto& ch : s1)
        count[ch]++;

    priority_queue<key> heap;
    for (int i=0; i<26; i++)
    {
        if (count[i]>0)
            heap.push({count[i], char('a'-i)});
    }

    key prev = {-1, '#'};
    while (!heap.empty())
    {
        key k = heap.top();
        heap.pop();

        s2 += k.c;
        if (prev.freq>0)
            heap.push(prev);

        k.freq--;
        prev = k;
    }

    if (s1.size() == s2.size())
        cout <<"valid string";
    else
    {
        cout <<"Not valid";
    }
    

}


int main()
{
    string inputStr = "aaabc";
    //string inputStr = "aaabb";
    //string inputStr = "aa";
    //string inputStr = "aaaabc";

    string outputStr;
    rearrange(inputStr, outputStr);

    if(outputStr.size() == 0)
        cout << "Not Possible "<< endl;
    else
        cout << outputStr << endl;

    return 0;
}