#include <iostream>

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

void inorderTrav(Node* root)
{
    if(root == NULL)
        return;
    
    inorderTrav(root->left);
    cout<< root->data <<" ";
    inorderTrav(root->right);
}

void preorderTrav(Node* root)
{
    if(root == NULL)
        return;
    
    cout<< root->data <<" ";
    preorderTrav(root->left);    
    preorderTrav(root->right);
}

int findIndex(char arr[], int size, char key)
{
    for(int i=0; i<size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

Node* constructTree(char inorder[], char preorder[], int size)
{   
    if(size == 0)
        return NULL;
    
    int index = findIndex(inorder, size, preorder[0]);
    Node* node = getNewTreeNode(preorder[0]);
    node->left = constructTree(inorder, preorder+1, index);
    node->right = constructTree(inorder+index+1, preorder+index+1, size-index-1);
    
    return node;
}

int main()
{
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C' };
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F'};

    int size = sizeof(inorder)/sizeof(inorder[0]);

    Node* root = constructTree(inorder, preorder, size);
    inorderTrav(root); cout <<endl;
    preorderTrav(root); cout <<endl;

    return 0;
}