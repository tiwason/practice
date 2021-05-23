#include <iostream>

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

bool checkSequence(Node* root, int arr[], int arrSize)
{
    if (root == NULL && arrSize == 0)
        return true;
    
    if (root)
    {
        arrSize = (root->data == arr[0]) ? arrSize-1 : arrSize;
        return (checkSequence(root->left, (root->data == arr[0]) ? arr+1 : arr, arrSize) 
                    || checkSequence(root->right, (root->data == arr[0]) ? arr+1 : arr, arrSize));
    }

    return false;
}

int main()
{
    Node *tree1 = getNewTreeNode(5); 
    tree1->left = getNewTreeNode(2); 
    tree1->right = getNewTreeNode(3);
    tree1->left->left = getNewTreeNode(1);
    tree1->left->right = getNewTreeNode(4);
    tree1->left->right->left = getNewTreeNode(6);
    tree1->left->right->right = getNewTreeNode(8);

    int arr[] = {5, 2, 4, 8};
    int size = sizeof(arr)/ sizeof(arr[0]);

    if(checkSequence(tree1, arr, size))
        cout << "Path found from root to leaf !!" <<endl;
    else
        cout << "Path not found from root to leaf !! " <<endl;    

    return 0;
}