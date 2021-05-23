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

bool isSumTree(Node* node)
{
    if(node == NULL)
        return true;
    
    int leftSum = node->left ?
                            isLeafNode(node->left) ? node->left->data : 2*node->left->data
                            : 0;
    int rightSum = node->right ?
                            isLeafNode(node->right) ? node->right->data : 2*node->right->data 
                            : 0;
    int sum = isLeafNode(node) ? node->data : (leftSum + rightSum);

    return ((sum == node->data) && isSumTree(node->left) && isSumTree(node->right));
}   

int main()
{
    Node *root = getNewTreeNode(26); 
    root->left = getNewTreeNode(10); 
    root->right = getNewTreeNode(3); 
    root->left->left = getNewTreeNode(4); 
    root->left->right = getNewTreeNode(6); 
    root->right->right = getNewTreeNode(3); 

    if (isSumTree(root))
        cout << "Sum Tree" << endl;
    else
        cout << "Not Sum tree" <<endl;

    return 0;
}