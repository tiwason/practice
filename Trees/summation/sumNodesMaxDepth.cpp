#include <iostream>
#include <climits>
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
    return (node->left == NULL && node->right == NULL);
}

void sumNodesMaxDepth(Node* root, int level, int& maxLevel, int& sum)
{
    if (root == NULL)
        return;
    
    if (level > maxLevel)
    {
        maxLevel = level;
        sum = root->data;
    }
    else if (level == maxLevel)
        sum += root->data;
    
    sumNodesMaxDepth(root->left, level+1, maxLevel, sum);
    sumNodesMaxDepth(root->right, level+1, maxLevel, sum);    
}

int main()
{
    Node *root = getNewTreeNode(1); 
    root->left = getNewTreeNode(2);
    root->right = getNewTreeNode(3);
    root->left->left = getNewTreeNode(4);
    root->left->right = getNewTreeNode(5);
    root->right->left = getNewTreeNode(6);
    root->right->right = getNewTreeNode(7);
  
    int maxLevel=1, sum=0;
    sumNodesMaxDepth(root, 1, maxLevel, sum);
    cout << "sum : " << sum <<endl;
    
    return 0;
}