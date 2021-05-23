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

bool checkDeadEnd(Node* root, int min, int max)
{
    if (root == NULL)
        return false;

    return (min == max) || checkDeadEnd(root->left, min, root->data-1) 
             || checkDeadEnd(root->right, root->data+1, max);  
}

int main()
{
    Node *root = getNewTreeNode(8); 
    root->left = getNewTreeNode(5);
    root->right = getNewTreeNode(9);
    root->left->left = getNewTreeNode(2);
    root->left->right = getNewTreeNode(7);
    root->left->left->left = getNewTreeNode(1);

    if (checkDeadEnd(root, 1, INT_MAX))
        cout << "Dead End !!";
    else
        cout <<" No Dead End !!";
    
    cout << endl;
    
    return 0;    
}