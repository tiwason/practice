#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int findNextGreaterIndex(int vec[], int key, int start, int end)
{
    for(int i=start; i <= end; i++)
    {
        if(vec[i] > key)
            return i;
    }
    return -1;
}

void printArray(int arr[], int start, int end)
{
    for(int i=start; i<= end; i++)
        cout <<arr[i]<<" ";
    cout<<endl;
}

//first elemnt of preorder is root for that subtree
void printPostOrder(int preorder[], int start, int end)
{
    if (start > end)  
        return;
    
    if(start == end)
    {
        cout << preorder[start] <<" ";
        return;
    }
    
    //printArray(preorder, start, end);
    int index = findNextGreaterIndex(preorder, preorder[start], start, end);
    if(index == -1 || index == start+1) //only left subtree or right subtree
    {
        printPostOrder(preorder, start+1, end);
    }
    else  //both left and right subtree
    {
        printPostOrder(preorder, start+1, index-1);
        printPostOrder(preorder, index, end);
    }
    
    cout << preorder[start] <<" ";
}

int main()
{
    //int preorder[] = {40, 30, 35, 80, 100};
    int preorder[] = {40, 30, 32, 35, 80, 90, 100, 120};
    int size = sizeof(preorder)/sizeof(preorder[0]);
    
    printPostOrder(preorder, 0, size-1);
    cout<<endl;
    return 0;
}
