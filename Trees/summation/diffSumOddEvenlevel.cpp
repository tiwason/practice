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

void sumNodesMaxDepth(Node* root, int level, int& sumOdd, int& sumEven)
{
    if (root == NULL)
        return;
    
    if ((level & 1) == 0)
        sumEven += root->data;
    else
        sumOdd += root->data;    
   
    sumNodesMaxDepth(root->left, level+1, sumOdd, sumEven);
    sumNodesMaxDepth(root->right, level+1, sumOdd, sumEven);    
}

int main()
{
    Node *root = getNewTreeNode(5); 
    root->left = getNewTreeNode(2);
    root->right = getNewTreeNode(6);
    root->left->left = getNewTreeNode(1);
    root->left->right = getNewTreeNode(4);
    root->right->right = getNewTreeNode(8);
    root->left->right->left = getNewTreeNode(3);
    root->right->right->left = getNewTreeNode(7);
    root->right->right->right = getNewTreeNode(9);
  
    int sumOdd=0, sumEven=0;
    sumNodesMaxDepth(root, 1, sumOdd, sumEven);
  
    cout << "Difference : " << (sumOdd - sumEven) <<endl;
    
    return 0;
}