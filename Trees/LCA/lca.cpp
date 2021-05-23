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

bool findLCA(Node* root, int a, int b, int& lca)
{
    if (root != NULL)
    {
        bool found = root->data == a || root->data == b;       
        bool foundInLeftST = findLCA(root->left, a, b, lca);
        bool foundInRightST = findLCA(root->right, a, b, lca);

        if(foundInLeftST && foundInRightST && lca == -1)
            lca = root->data;
        else if ((foundInLeftST || foundInRightST) && found && lca == -1)
            lca = root->data;
        
        return (foundInLeftST || foundInRightST || found);
    }
    
    return false;
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
    
    int lca = -1;
    findLCA(root, 2, 4, lca); //4,5 4,6 3,4 2,4

    cout << "LCA is: " << lca <<endl;
   
    return 0;
}