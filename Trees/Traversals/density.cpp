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

int getDensity(Node* node, int& size) //returns height
{
    if(node == NULL)
        return 0;
    
    size++;
    if (isLeafNode(node))
        return 1;
    
    int height = max(getDensity(node->left, size), getDensity(node->right, size)) + 1;
    return height;
}

int main()
{
    Node* root = getNewTreeNode(8);
    Node* rootLeft = getNewTreeNode(3);
    Node* rootLeftLeft = getNewTreeNode(10);
   
    root->left = rootLeft;
    root->left->left = rootLeftLeft;

    int size = 0;
    int height = 0;
    height = getDensity(root, size);
    cout << "Density of tree is "<< (static_cast<double> (size)/height) <<endl; 

    return 0;
}