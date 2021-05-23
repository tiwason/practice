#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <sstream>

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

int findLCA(Node* root, int a, int b)
{
    if(root == NULL)
        return -1;
    
    if (a < root->data && b < root->data)
        return findLCA(root->left, a, b);
    
    if(a > root->data && b > root->data)
        return findLCA(root->right, a, b); 
    
    return root->data;
}


int main()
{
    Node *root = getNewTreeNode(20); 
    root->left = getNewTreeNode(8);
    root->right = getNewTreeNode(22);
    root->left->left = getNewTreeNode(4);
    root->left->right = getNewTreeNode(12);
    root->left->right->left = getNewTreeNode(10);
    root->left->right->right = getNewTreeNode(14);  
    
    cout << "LCA is: " << findLCA(root, 4, 22) <<endl;
   
    return 0;
}