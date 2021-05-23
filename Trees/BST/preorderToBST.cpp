#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int findLastSmallIndex(int arr[], int size)
{
    int  key = arr[0];
    int i = 0;
    
    while(i < size && arr[i] <= key)
        i++;

    return i-1;
}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

Node* constructBST(int preorder[], int size)
{
    if(size <= 0)
        return NULL;
    
    printArray(preorder, size);
    
    Node* root = getNewNode(preorder[0]);
    int index = findLastSmallIndex(preorder, size);
    
    root->left = constructBST(preorder+1, index);
    root->right = constructBST(preorder+index+1, size-index-1);

    return root;
}

int main()
{
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder)/sizeof(preorder[0]);

    Node* root = constructBST(preorder, size);
    inorder(root); cout <<endl;

    return 0;
}