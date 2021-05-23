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

void getLongestPathSum(Node* tree, int height, int sum, int& maxSum, int& maxHeight)
{
    if (tree == NULL)
        return;
    
    sum += tree->data;
    if (height > maxHeight)
    {
        maxSum = sum;
        maxHeight = height;
    }
    else if(height == maxHeight)
    {
        if (maxSum < sum)
            maxSum = sum;
    }

    getLongestPathSum(tree->left, height+1, sum, maxSum, maxHeight);
    getLongestPathSum(tree->right, height+1, sum, maxSum, maxHeight);
}

int main()
{
    Node* root = getNewTreeNode(4);         /*        4        */
    root->left = getNewTreeNode(2);         /*       / \       */
    root->right = getNewTreeNode(5);        /*      2   5      */
    root->left->left = getNewTreeNode(7);   /*     / \ / \     */
    root->left->right = getNewTreeNode(1);  /*    7  1 2  3    */
    root->right->left = getNewTreeNode(2);  /*      /   \       */
    root->right->right = getNewTreeNode(3); /*     6     3      */
    root->left->right->left = getNewTreeNode(6);
    root->right->left->right = getNewTreeNode(3);
    
    int maxSum = INT_MIN, maxHeight=0;
    getLongestPathSum(root, 0, 0, maxSum, maxHeight);
    cout << "Longest path sum is " << maxSum << endl;

    return 0;
}