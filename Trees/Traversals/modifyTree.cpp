#include <iostream>
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

//returns rightmost node in left subtree
Node* modifyTree(Node* node)
{
    if (node == NULL)
        return NULL;
    
    Node* right = node->right;
    Node* rightMost = node;

    if (node->left)
    {
        rightMost = modifyTree(node->left);
        node->right = node->left;
        node->left = NULL;
    }

    if (!right)
        return rightMost;
    
    rightMost->right = right;
    rightMost = modifyTree(right);   
    return rightMost;
}

void traversal(Node* node)
{
    if(node == NULL)
        return;
    cout<<node->data <<" ";
    traversal(node->right);
}

int main()
{
    Node* root = getNewTreeNode(10); 
    root->left = getNewTreeNode(8); 
    root->right = getNewTreeNode(2); 
    root->left->left = getNewTreeNode(3); 
    root->left->right = getNewTreeNode(5); 

    modifyTree(root);
    traversal(root);
    cout <<endl;

    return 0;
}