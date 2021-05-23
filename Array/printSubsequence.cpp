#include <iostream>
#include <math.h>

using namespace std;

void printSubSeq(int arr[], int size)
{
    int seqSize = pow(2, size);

    for(int counter = 1; counter < seqSize; counter++)
    {
        for(int i=0; i<size; i++)
        {
            if(counter & (1<<i))
                cout <<arr[i] <<" ";
        }
        cout <<endl;
    }
}

int main()
{
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    printSubSeq(arr, size);
    
    return 0;
}