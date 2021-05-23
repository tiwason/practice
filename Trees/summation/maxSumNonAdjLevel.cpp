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
int getMaxSum(Node* root)
int getSumAlternate(Node* root)
{
    if(root == NULL)
        return 0;
    
    int sum = root->data;
    if(root->left)
    {
        sum += getMaxSum(root->left->left);
        sum += getMaxSum(root->left->right);
    }

    if(root->right)
    {
        sum += getMaxSum(root->right->left);
        sum += getMaxSum(root->right->right);
    }

    return sum;
}

int getMaxSum(Node* root)
{
    if(root == NULL)
        return 0;
    
    return(max(getSumAlternate(root), 
                getSumAlternate(root->left)+getSumAlternate(root->right)));
}

int main()
{
    Node* root = getNewTreeNode(1); 
    root->left = getNewTreeNode(2); 
    root->right = getNewTreeNode(3); 
    root->right->left = getNewTreeNode(4);
    root->right->left->right = getNewTreeNode(5);
    root->right->left->right->left = getNewTreeNode(6);

    
  
    return 0;
}