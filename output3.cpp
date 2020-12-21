#include <iostream>
using namespace std;

int x = 10;

class Base
{
        int &x = ::x;
    public:
        Base(){}
        Base(int i) {x = i;}
        void print() {cout << x <<endl;}
};

int main()
{
    Base b;
    b.print();
}