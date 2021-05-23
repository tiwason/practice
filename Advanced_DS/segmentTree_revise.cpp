#include <iostream>
#include <math.h>

using namespace std;

int constructSTUtil(int arr[], int start, int end, int *st, int index)
{
    if (start > end)
        return;

    if (start == end)
    {
        st[index] = arr[start];
        return arr[start];
    }
    int mid = start + (end - start) / 2;
    int left = constructSTUtil(arr, start, mid, st, 2 * index + 1);
    int right = constructSTUtil(arr, mid + 1, end, st, 2 * index + 2);
    arr[index] = left + right;
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

int getSumUtil(int *st, int start, int end, int l, int r, int index)
{
    if (l > end || r < start)
        return 0;

    if (start >= l && end <= r)
        return st[index];

    int mid = start + (end - start) / 2;
    return (getSumUtil(st, 0, mid, l, r, 2 * index + 1) +
            getSumUtil(st, mid + 1, end, l, r, 2 * index + 2));
}

int getSum(int *st, int size, int l, int r)
{
    return getSumUtil(st, 0, size - 1, l, r, 0);
}

void updateValueUtil(int arr[], int *st, int start, int end, int idx, int diff, int i)
{
    if (idx < start || idx > end)
        return;

    st[i] = st[i] + diff;

    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    updateValueUtil(arr, st, start, mid, idx, diff, 2 * i + 1);
    updateValueUtil(arr, st, mid + 1, end, idx, diff, 2 * i + 2);
}

void updateValue(int arr[], int *st, int n, int index, int newValue)
{
    int diff = newValue - arr[index];
    arr[index] = newValue;
    updateValueUtil(arr, st, 0, n - 1, index, diff);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *st = constructST(arr, n);

    cout << "Sum of values in given range = " << getSum(st, n, 1, 3) << endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, st, n, 1, 10);

    // Find sum after the value is updated
    cout << "Updated sum of values in given range = "
         << getSum(st, n, 1, 3) << endl;
    return 0;
}