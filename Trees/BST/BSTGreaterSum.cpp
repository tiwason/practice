#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* getNewNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BSTSumTree(Node* root, int& sum)
{
    if (root == NULL)
        return;
    
    int temp = root->data;
    BSTSumTree(root->right, sum);
    root->data = sum;
    sum += temp;
    BSTSumTree(root->left, sum);
}

int main()
{
    Node* root= getNewNode(11);
    root->left = getNewNode(2);
    root->right = getNewNode(29);
    root->left->left = getNewNode(1);
    root->left->right = getNewNode(7);
    root->right->left = getNewNode(15);
    root->right->right = getNewNode(40);
    root->right->right->left = getNewNode(35);

    int sum = 0;
    BSTSumTree(root, sum);
    preorder(root);
    cout << endl;
}