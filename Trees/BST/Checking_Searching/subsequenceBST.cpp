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

void checkSequence(Node* root, int seq[], int size, int& index)
{
    if (root == NULL)
        return;

    if (index == size)
        return;
    
    // sequence may exist in left subtree
    if(seq[index] < root->data)
        checkSequence(root->left, seq, size, index);
   
    if (root->data == seq[index])
        index++;

    //sequence may exist in only right subtree
    if(root->data < seq[index])
        checkSequence(root->right, seq, size, index);
}

int main()
{
    Node *root = getNewTreeNode(8); 
    root->left = getNewTreeNode(3);
    root->right = getNewTreeNode(10);
    root->left->left = getNewTreeNode(1);
    root->left->right = getNewTreeNode(6);
    root->left->right->left = getNewTreeNode(4);
    root->left->right->right = getNewTreeNode(7); 
    root->right->right = getNewTreeNode(14);
    root->right->right->left = getNewTreeNode(13);

    int seq[] = {10, 15};
    //int seq[] = {4, 6, 8, 12, 13};
    int size = sizeof(seq)/sizeof(seq[0]);
    int index = 0;

    checkSequence(root, seq, size, index);
    if (index == size)
        cout << "YES !!" <<endl;
    else
        cout << "NO !!" <<endl;
    
    return 0;    
}