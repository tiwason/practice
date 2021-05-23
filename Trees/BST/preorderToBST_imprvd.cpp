#include <iostream>
#include <climits>

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

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

Node* constructBST(int preorder[], int startRange, int endRange, int size, int& index)
{
    if(index == size)
        return NULL;
    
    if(preorder[index] < startRange || preorder[index] > endRange)
        return NULL;

    int save = preorder[index];
    Node* root = getNewNode(preorder[index]); index++;
    root->left = constructBST(preorder, startRange, save, size, index);
    root->right = constructBST(preorder, save, endRange, size, index);

    return root;
}

int main()
{
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder)/sizeof(preorder[0]);

    int index = 0;
    Node* root = constructBST(preorder, INT_MIN, INT_MAX, size, index);
    inorder(root); cout <<endl;

    return 0;
}