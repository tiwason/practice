#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int findIndex(vector<int> vec, int key)
{
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] == key)
            return i;
    }
    return -1;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout <<arr[i]<<" ";
    cout<<endl;
}

int searchElem(int arr[], int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(key == arr[i])
            return i;
    }
    return -1;
}

//first elemnt of preorder is root for that subtree
void printPostOrder(int inorder[], int preorder[], int size)
{
    if (size == 0)  
        return;

    int index = searchElem(inorder, size, preorder[0]);
    if(index == 0) //left subtree is empty, postorder on right subtree only
        printPostOrder(inorder+1, preorder+1, size-1);
    else if(index == size-1) // right subtree empty, postorder on left subtree
        printPostOrder(inorder, preorder+1, size-1);
    else
    {//postorder on both left and right subtree
        printPostOrder(inorder, preorder+1, index);

        int i = searchElem(preorder, size, inorder[index+1]);
        printPostOrder(inorder+index+1, preorder+i, size-i);
    }
    cout << preorder[0] <<" ";
}

int main()
{
    int inorder[] = {4, 2, 5, 1, 3, 6};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int size = sizeof(inorder)/sizeof(inorder[0]);
    
    printPostOrder(inorder, preorder, size);
    cout<<endl;
    return 0;
}
