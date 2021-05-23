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

bool findDistance(Node* root, int a, int b, int level, int& distance)
{
    if (root != NULL)
    {  
        int lDistance = 0, rDistance = 0;
        bool found = root->data == a || root->data == b;       
        bool foundInLeftST = findDistance(root->left, a, b, level+1, lDistance);
        bool foundInRightST = findDistance(root->right, a, b, level+1, rDistance);
        
        if(foundInLeftST && foundInRightST && distance == 0)
            distance = lDistance + rDistance - 2*level;
        else if(foundInLeftST && found && distance == 0)
            distance = lDistance + level - 2*level;
        else if(foundInRightST && found && distance==0)
            distance = rDistance + level -2*level;
        else
            distance = foundInLeftST ? lDistance : foundInRightST ? rDistance : found ? level : 0;
        
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
    root->right->left->right = getNewTreeNode(8);
    
    int distance = 0;
    findDistance(root, 8, 5, 0, distance);
    cout << "Distance is: " <<  distance << endl;
   
    return 0;
}