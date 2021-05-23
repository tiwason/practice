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

bool isMirror(Node* tree1, Node* tree2)
{
    if(tree1 == NULL && tree2 == NULL)
        return true;
    
    if((tree1 && tree2) && (tree1->data == tree2->data))
        return (isMirror(tree1->left, tree2->right)
                  && isMirror(tree1->right, tree2->left));
    
    return false;
}

bool isSymmetric(Node* root)
{
    return isMirror(root, root);
}

int main()
{
    Node* root = getNewTreeNode(1);
    Node* rootLeft = getNewTreeNode(2);
    Node* rootRight = getNewTreeNode(2);
    Node* rootLeftLeft = getNewTreeNode(3);
    Node* rootLeftRight = getNewTreeNode(4);
    Node* rootRightLeft = getNewTreeNode(4);
    Node* rootRightRight = getNewTreeNode(3);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootLeft->right = rootLeftRight;
    rootRight->left = rootRightLeft;
    rootRight->right = rootRightRight;

    if(isSymmetric(root))
        cout << "Tree is symmetrical" <<endl;
    else
        cout << "Tree is not symmetrical" <<endl;
    
   return 0;
}