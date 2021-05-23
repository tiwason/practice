#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* getNewTreeNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bool isLeafNode(Node* node)
{
    return (node->left==NULL && node->right == NULL);
}

int getIndex(int arr[], int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] <<" ";
    cout <<endl;
}

bool checkTravSameTree(int inorder[], int preorder[], int postorder[], int size)
{
    if (size == 1)
        return ((inorder[0] == preorder[0]) && (preorder[0] == postorder[0]));

    int index = getIndex(inorder, size, preorder[0]);
    return (checkTravSameTree(inorder, preorder+1, postorder, index) &&
                checkTravSameTree(inorder+index+1, preorder+index+1, postorder+index, size-index-1));
}

int main()
{
    int inorder[] = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    int size = sizeof(inorder)/inorder[0];
    if (checkTravSameTree(inorder, preorder, postorder, size))
        cout << "Traversal belong to same tree" <<endl;
    else
        cout << "Traversal doesnt belong to same tree" <<endl;
    
    return 0;
}