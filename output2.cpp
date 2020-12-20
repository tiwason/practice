#include <iostream>

using namespace std;

class Base
{
        int x;
        int y;
    public:
        Base() {cout <<"0" <<endl;}
        Base(int x1, int y1)
        {
           x = x1;
           y = y1;
           cout <<"parameter"<<endl;
        }

        Base(const Base& b)
        {
            x = b.x;
            cout << "copy constructor"<<endl;
        }
};

int main()
{
    Base b1 = {10, 20};
   
    return 0;
}