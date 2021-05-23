#include <iostream>
#include <vector>
#include <unordered_set>

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

void leftBoundaryTraversal(Node* node, unordered_set<int>& s)
{
    if(node == NULL)
        return;
    
    cout << node->data << " ";
    s.insert(node->data);
    leftBoundaryTraversal(node->left, s);
}

void rightBoundaryTraversal(Node* node, unordered_set<int>& s)
{
    if(node == NULL)
        return;

    rightBoundaryTraversal(node->right, s);
    if(s.find(node->data) == s.end())
    {
        cout << node->data << " ";
        s.insert(node->data);
    }
}

void bottomBoundaryTraversal(Node* node, unordered_set<int>& s)
{
    if(node==NULL)
        return;
    
    if(node->left == NULL && node->right == NULL)
    {
        if(s.find(node->data) == s.end())
        {
            cout << node->data << " ";
            s.insert(node->data);
        }
    }

    bottomBoundaryTraversal(node->left, s);
    bottomBoundaryTraversal(node->right, s);
}

void boundaryTraversal(Node* root)
{
    unordered_set<int> s;
    leftBoundaryTraversal(root, s);
    bottomBoundaryTraversal(root, s);
    rightBoundaryTraversal(root, s);
    cout<<endl;
}


int main()
{
    Node* root = getNewTreeNode(8);
    Node* rootLeft = getNewTreeNode(3);
    Node* rootRight = getNewTreeNode(10);
    Node* rootLeftLeft = getNewTreeNode(1);
    Node* rootRightLeft = getNewTreeNode(6);
    Node* rootRightRight = getNewTreeNode(14);
    Node* rootRightRightLeft = getNewTreeNode(13);
    Node* rootRightLeftLeft = getNewTreeNode(4);
    Node* rootRightLeftRight =  getNewTreeNode(7);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootRight->left = rootRightLeft;
    rootRight->right = rootRightRight;
    rootRightRight->left = rootRightRightLeft;
    rootRightLeft->left = rootRightLeftLeft;
    rootRightLeft->right = rootRightLeftRight;

    boundaryTraversal(root);
    return 0;
}