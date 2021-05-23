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
    return (node->left==NULL && node->right == NULL);
}

bool chkChildrenSumProperty(Node* node)
{
    if(node == NULL || isLeafNode(node))
        return true;
    
    int leftData = node->left ? node->left->data : 0;
    int rightData = node->right ? node->right->data : 0;
      
    return ((node->data == leftData+rightData) && chkChildrenSumProperty(node->left)
                        && chkChildrenSumProperty(node->right));
}   

int main()
{
    Node *root = getNewTreeNode(10); 
    root->left = getNewTreeNode(9); 
    root->right = getNewTreeNode(2); 
    root->left->left = getNewTreeNode(3); 
    root->left->right = getNewTreeNode(5); 
    root->right->right = getNewTreeNode(2); 

    if (chkChildrenSumProperty(root))
        cout << "Tree holds children sum property" << endl;
    else
        cout << "Tree doesnt hold children sum property" <<endl;

    return 0;
}