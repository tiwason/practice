#include <iostream>

using namespace std;

int reverseBits(unsigned int x)
{
    int no_of_bits = sizeof(x) * 8;
    unsigned int reverse_num=0;

    for (int i=0; i<no_of_bits; i++)
    {
        unsigned int tmp = (x & 1<<i);
        if (tmp)
            reverse_num |= (1 << (no_of_bits -1-i));

    }
    return reverse_num;

}

int reverseBits2(unsigned int x)
{
    int count = sizeof(x) * 8 - 1;
    unsigned int reverse_num = x;

    while (x)
    {
        count--;
        reverse_num <<= 1;
        reverse_num |= (x & 1);
        x = x>>1;
    }
    reverse_num <<= count;
    return reverse_num;
}

int main() 
{ 
    unsigned int x = 2;  
    cout << reverseBits(x) << endl; 
} 