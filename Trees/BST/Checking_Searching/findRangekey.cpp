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

void findPreSuc(Node* root, Node*& pre, Node*& succ, int key)
{
    if (root == NULL)
        return;
    
    if(root->data > key)
    {
        succ = root;
        findPreSuc(root->left, pre, succ, key);
    }
    else if (root->data < key)
    {
        pre = root;
        findPreSuc(root->right, pre, succ, key);
    }
    else//equal case
    {
        if(root->left)
        {
            Node* temp = root->left;
            while(temp)
                temp = temp->right;
            
            pre = temp;
        }

        if(root->right)
        {
            Node* temp = root->right;
            while(temp)
                temp = temp->left;
            
            succ = temp;
        }
    }
}

int main()
{
    Node* root = getNewTreeNode(50);
    root->left = getNewTreeNode(30);
    root->right = getNewTreeNode(70);
    root->left->left = getNewTreeNode(20);
    root->left->right = getNewTreeNode(40);
    root->right->left = getNewTreeNode(60);
    root->right->right = getNewTreeNode(80);

    int key = 65;
    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, key);

    if(pre)
        cout << pre->data << endl;
    
    if(suc)
        cout << suc->data << endl;

    return 0;
}
