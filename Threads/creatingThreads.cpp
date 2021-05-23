#include <iostream>
#include <thread>

using namespace std;

/*void fun(int x)
{
    while (x-- > 0)
        cout << x << endl;
}*/

/* functor 
class base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
            cout << x << endl;
    }
}; */

/* Non static/static member function */
class base
{
public:
    static void fun(int x)
    {
        while (x-- > 0)
            cout << x << endl;
    }
};

int main()
{

    /* 1. function pointers
    std::thread t1(fun, 10);
    t1.join(); */

    /* 2. lambda function 
    auto fun = [](int x) {
        while (x-- > 0)
            cout << x << endl;
    };

    std::thread t(fun, 10);
    t.join(); */

    /*3. function objects 
    std::thread t(base(), 10);
    t.join(); */

    /* 4. Non static member function 
    base b;
    std::thread t(&base::fun, &b, 11); // address of function, this ptr, argument
    t.join(); */

    /* static member function */
    std::thread t(&base::fun, 20); // we dont need this pointer in case of static
    t.join();

    return 0;
}