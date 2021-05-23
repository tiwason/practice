#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

/*
Thread is a lightweight process and used for parallelism.
ways to craete threads :
1. function pointer
2. lambda functions
3. functors
4. member functions
5. static member functions

*/

ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i & 1) == 0)
            EvenSum += i;
    }
}

void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if (i & 1)
            OddSum += i;
    }
}

int main()
{
    ull start = 1, end = 1900000000;

    auto startTime = high_resolution_clock::now();
    //findOdd(start, end);
    //findEven(start, end);

    // Function Pointers
    std::thread t1(findOdd, start, end);
    std::thread t2(findEven, start, end);

    // join these threads to main thread
    t1.join();
    t2.join();

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);

    cout << "OddSum = " << OddSum << endl;
    cout << "EvenSum = " << EvenSum << endl;
    cout << "Time = " << duration.count() / 1000000 << endl;
    return 0;
}