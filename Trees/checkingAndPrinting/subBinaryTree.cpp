#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* getNewTreeNode(char data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void preorder(Node* root, string& pre)
{
    if(root == NULL)
        return;
    
    pre += root->data;
    preorder(root->left, pre);
    preorder(root->right, pre);
}

void inorder(Node* root, string& in)
{
    if(root == NULL)
        return;
    
    inorder(root->left, in);
    in += root->data;
    inorder(root->right, in);
}

bool isSubtree(Node* tree1, Node* tree2)
{
    if(tree1 == NULL && tree2 == NULL)
        return true;
    
    string tree1_pre, tree1_in, tree2_pre, tree2_in;
    preorder(tree1, tree1_pre);
    inorder(tree1, tree1_in);

    preorder(tree2, tree2_pre);
    inorder(tree2, tree2_in);

    return (tree2_pre.find(tree1_pre) != string::npos 
                    && tree2_in.find(tree1_in) != string::npos);
}

int main()
{
    Node *tree1 = getNewTreeNode('x'); 
    tree1->left = getNewTreeNode('a'); 
    tree1->right = getNewTreeNode('b');
    tree1->left->right = getNewTreeNode('c');

    Node* tree2 = getNewTreeNode('z');
    tree2->left = getNewTreeNode('x');
    tree2->right = getNewTreeNode('e');
    tree2->left->left = getNewTreeNode('a');
    tree2->left->right = getNewTreeNode('b');
    tree2->left->left->right = getNewTreeNode('c');
    tree2->right->right = getNewTreeNode('k');

    if(isSubtree(tree1, tree2))
        cout <<" Subtree"<<endl;
    else
        cout <<"Not a subtree" <<endl;

    return 0;
}