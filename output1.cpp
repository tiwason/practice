#include <iostream>

using namespace std;

class Base
{
        int x;
        int y;
    public:
        Base() {}
        Base(int x1, int y1)
        {
            Base temp;
            temp.x = x1;
            temp.y = y1;
            *this = temp;//call to assignment operator
        }

        void print()
        {
            cout<<"x= "<<x <<"  "<<"y= "<<y<<endl;
        }
};

int main()
{
    Base b1(10, 20);
    b1.print();

    return 0;
}