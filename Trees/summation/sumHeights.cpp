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

int getSumHeights(Node* root, int& sum)
{
    if(root == NULL)
        return 0;
    
    int leftH = getSumHeights(root->left, sum);
    int rightH = getSumHeights(root->right, sum);
    int level = max(leftH, rightH) + 1;
    sum += level;

    return level;
}

int main()
{
    Node *root = getNewTreeNode(1); 
    root->left = getNewTreeNode(2);
    root->right = getNewTreeNode(3);
    root->left->left = getNewTreeNode(4);
    root->left->right = getNewTreeNode(5);
  
    int sum = 0;
    getSumHeights(root, sum);
    cout <<"sum of heights : " << sum <<endl;
    return 0;
}