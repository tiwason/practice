#include <iostream>
#include <climits>
#include <utility>

using namespace std;

typedef pair<int, int> PairSum;

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

//returns pair<inclSum, exclSum>
PairSum getMaxNonAdjacentSum(Node* root)
{
    if (root == NULL)
        return {0,0};
    
    PairSum leftSum = getMaxNonAdjacentSum(root->left);
    PairSum rightSum = getMaxNonAdjacentSum(root->right);

    int inclSum = leftSum.second + rightSum.second + root->data;
    //either of left or hild child is included for negative data cases
    int exclSum = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);
    return {inclSum, exclSum};  
}

int main()
{
    Node* root = getNewTreeNode(1); 
    root->left = getNewTreeNode(2); 
    root->right = getNewTreeNode(3); 
    root->left->left = getNewTreeNode(1);
    root->right->left = getNewTreeNode(4);
    root->right->right = getNewTreeNode(5); 

   
    PairSum sum = getMaxNonAdjacentSum(root);
    cout << ((sum.first > sum.second) ? sum.first : sum.second) <<endl;
  
    return 0;
}