#include <iostream>

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

bool isLeafNode(Node* tree)
{
    return (tree->left == NULL && tree->right == NULL);
}

int findSum(Node* tree)
{
    if(tree == NULL)
        return 0;
    
    if(isLeafNode(tree))
        return tree->data;
    
    return (tree->data + findSum(tree->left) + findSum(tree->right));
}


int main()
{
    Node *tree1 = getNewTreeNode(15); 
    tree1->left = getNewTreeNode(10); 
    tree1->right = getNewTreeNode(20);
    tree1->left->left = getNewTreeNode(8);
    tree1->left->right = getNewTreeNode(12);
    tree1->right->left = getNewTreeNode(16);
    tree1->right->right = getNewTreeNode(25);

    cout <<findSum(tree1) <<endl;

    return 0;
}