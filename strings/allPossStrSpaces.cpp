#include <iostream>
#include <math.h>

using namespace std;

void printAllPossible(string& str, int index, string s)
{

    s += str[index];

    if (index == str.size()-1)
    {
        cout <<endl << s << endl;
        return;
    }

    printAllPossible(str, index+1, s);
    printAllPossible(str, index+1, s+' ');
}

void printSubsequences(string& str)
{
    int length = str.size();
    int counter = pow(2, length-1);

    for (int i=0; i<counter; i++)
    {
        for (int j=0; j<length; j++)
        {
            cout << str[j];
            if (i & (1 << j))
                cout <<" ";
        }
        cout <<endl;
    }
}

int main()
{
    string str = "ABCD";
    //printAllPossible(str, 0, "");
    printSubsequences(str);
    return 0;
}