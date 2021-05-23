#include <iostream>
#include <climits>

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
    return (node->left == NULL && node->right == NULL);
}

void findMaxDiff(Node* root, int max, int& maxDiff)
{
    if(root == NULL)
        return;
    
    int diff = max - root->data;
    maxDiff = (maxDiff < diff) ? diff : maxDiff;
    max = max < root->data ? root->data : max;

    findMaxDiff(root->left, max, maxDiff);
    findMaxDiff(root->right, max, maxDiff);
}

int main()
{
    Node *root = getNewTreeNode(8); 
    root->left = getNewTreeNode(3);
    root->right = getNewTreeNode(10);
    root->left->left = getNewTreeNode(1);
    root->left->right = getNewTreeNode(6);
    root->right->right = getNewTreeNode(14);
    root->right->right->left = getNewTreeNode(13);
    root->left->right->left = getNewTreeNode(4);
    root->left->right->right = getNewTreeNode(7);

    int max = root->data, maxDiff = INT_MIN;
    findMaxDiff(root, max, maxDiff);
    cout << "Maximum diff "<< maxDiff <<endl;
    
    return 0;
}