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

int countSubTreeWithSumK(Node* root, int k, int& sum)
{
    if (root == NULL)
        return 0;

    int lsum = 0, rsum = 0;
    int count = countSubTreeWithSumK(root->left, k, lsum) 
                    + countSubTreeWithSumK(root->right, k, rsum);
    
    sum = lsum + rsum + root->data;
    
    if(sum == k)
        count++;
    
    return count;
}

int main()
{
    Node *root = getNewTreeNode(5); 
    root->left = getNewTreeNode(-10);
    root->right = getNewTreeNode(3);
    root->left->left = getNewTreeNode(9);
    root->left->right = getNewTreeNode(8);
    root->right->left = getNewTreeNode(-4);
    root->right->right = getNewTreeNode(7);
  
    int sum=0;
    cout << "Count : " << countSubTreeWithSumK(root, 7, sum) <<endl;
    
    return 0;
}