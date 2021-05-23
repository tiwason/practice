#include <iostream>

using namespace std;

void moveSpaceInFront(string& str)
{
    int i = str.size()-1;
    for (int j=i; j>=0; j--)
    {
        if (str[j] != ' ')
        {
            str[i] = str[j];
            i--;
        }            
    }

    while(i >= 0)
    {
        str[i] = ' ';
        i--;
    }
}

int main()
{
    string str("Hey there, it's GeeksforGeeks");
    cout << str<<endl;
    moveSpaceInFront(str);
    cout << str <<endl;
    return 0;
}