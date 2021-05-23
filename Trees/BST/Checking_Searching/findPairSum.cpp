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

bool findPairSum(Node* root1, Node* root2, int sum)
{
    if (root == NULL)
        return false;
    
    findPairSum(root->left, sum);
    findPairSum(root->right, sum);
}

int main()
{
    Node* root = getNewTreeNode(15);
    root->left = getNewTreeNode(10);
    root->right = getNewTreeNode(20);
    root->left->left = getNewTreeNode(8);
    root->left->right = getNewTreeNode(12);
    root->right->left = getNewTreeNode(16);
    root->right->right = getNewTreeNode(25);

    int sum = 33;

    return 0;
}
