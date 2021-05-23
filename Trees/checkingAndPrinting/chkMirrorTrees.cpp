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

bool isMirror(Node* tree1, Node* tree2)
{
    if(tree1 == NULL && tree2 == NULL)
        return true;
    else if(tree1 != NULL && tree2 != NULL)
        return (tree1->data == tree2->data && isMirror(tree1->left, tree2->right)
                     && isMirror(tree1->right, tree2->left));
    else
        return false;
}

int main()
{
    Node *tree1 = getNewTreeNode(1); 
    tree1->left = getNewTreeNode(3); 
    tree1->right = getNewTreeNode(2);
    tree1->right->left = getNewTreeNode(5);
    tree1->right->right = getNewTreeNode(4);

    Node* tree2 = getNewTreeNode(1);
    tree2->left = getNewTreeNode(2);
    tree2->right = getNewTreeNode(3);
    tree2->left->left = getNewTreeNode(4);
    tree2->left->right = getNewTreeNode(5);
   
    if(isMirror(tree1, tree2))
        cout << "Mirror !!";
    else
        cout <<"Not Mirror !!";    

    return 0;
}