#include <iostream>
#include <math.h>

using namespace std;


int getSumUtil(int* st, int start, int end, int l,int r, int index)
{
    if (r < start || l > end)
        return 0;
    else if(l <= start && r >= end)
        return st[index];
    
    int mid = start + (end-start)/2;
    return (getSumUtil(st, start, mid, l, r, 2*index+1) +
                getSumUtil(st, mid+1, end, l, r, 2*index+2));
}

int getSum(int* st, int n, int l, int r)
{
   return getSumUtil(st, 0, n-1, l, r, 0);
}

int constructSTUtil(int arr[], int start, int end, int* st, int index)
{
    if (start == end)
    {
        st[index] = arr[start];
        return st[index];
    }

    int mid = start + (end-start)/2;
    st[index] = constructSTUtil(arr, start, mid, st, 2*index+1) +
                    constructSTUtil(arr, mid+1, end, st, 2*index+2);
    
    return st[index];
}

int* constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
 
    int *st = new int[max_size];
 
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

void updateValueUtil(int* st, int start, int end, int index, int diff, int i)
{
    if (i < start || i > end)
        return;
   
    st[index] = st[index] + diff;
  
    if (start == end)
        return;
    int mid = start + (end-start)/2;
    updateValueUtil(st, start, mid, 2*index+1, diff, i);
    updateValueUtil(st, mid+1, end, 2*index+2, diff, i);
}

void updateValue(int arr[], int* st, int n, int index, int newValue)
{
    int diff = newValue - arr[index];
    arr[index] = newValue;
    updateValueUtil(st, 0, n-1, 0, diff, index);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    int *st = constructST(arr, n);
 
    cout<<"Sum of values in given range = "<<getSum(st, n, 1, 3)<<endl;
 
    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);
 
    // Find sum after the value is updated
    cout<<"Updated sum of values in given range = "
            <<getSum(st, n, 1, 3)<<endl;
    return 0;
}