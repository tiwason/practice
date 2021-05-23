#include <iostream>
#include <climits>

using namespace std;

bool checkIdentical(int bst1[], int bst2[], int size, int i1, 
                        int i2, int max, int min)
{
   
    int j, k;

    for (j=i1; j<size; j++)
    {
        if(bst1[j] > min && bst1[j] < max)
            break;
    }

    for (k=i2; k<size; k++)
    {
        if(bst2[k] > min && bst2[k] < max)
            break;
    }

    //leaf node
    if(j==size && k==size)
        return true;
    
    if(j==size || k == size || bst1[j] != bst2[k])
        return false;
    
    return (checkIdentical(bst1, bst2, size, j+1, k+1, min, bst1[j]) 
                && checkIdentical(bst1, bst2, size, j+1, k+1, bst1[j], max));
}

int main()
{
    int bst1[] = {2, 4, 3, 1};
    int bst2[] = {2, 1, 4, 3};
    int size = sizeof(bst1)/sizeof(bst1[0]);

    if (checkIdentical(bst1, bst2, size, 0, 0, INT_MAX, INT_MIN))
        cout <<" Identical BSTs " <<endl;
    
    else
        cout << "Not identical BSTs " <<endl;

    return 0;
}