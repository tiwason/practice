#include <iostream>
#include <climits>

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

bool isLeafNode(Node* root)
{
    return (root->left == NULL && root->right == NULL);
}


void inorder(Node* root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

struct SwapInfo
{
    Node* parentA;
    Node* parentB;
    bool childA;
    bool childB;
};
//incorrect
void correctBST(Node* root, int min, int max, SwapInfo& s)
{
    if (!root)
        return;

    if (s.parentA && s.parentB)
        return;
    
    if (root->left)
    {
        if (root->left->data > min && root->left->data < root->data)
            correctBST(root->left, min, root->data, s);
        else
        {
            if (s.parentA)
            {
                s.parentB = root;
                s.childB = 0;
            }
            else
            {
                s.parentA = root;
                s.childA = 0;
            }
        }  
    }

    if (root->right)
    {
        if (root->right->data > root->data && root->right->data < max)
            correctBST(root->right, root->data, max, s);
        else
        {
            if (s.parentA)
            {
                s.parentB = root;
                s.childB = 1;
            }
            else
            {
                s.parentA = root;
                s.childA = 1;
            }
        }  
    }

}


int main()
{
    Node *root = getNewTreeNode(10); 
    root->left = getNewTreeNode(5);
    root->right = getNewTreeNode(8);
    root->left->left = getNewTreeNode(2);
    root->left->right = getNewTreeNode(20);

    inorder(root); cout <<endl;
    SwapInfo s; s.parentB = s.parentA = NULL;
    correctBST(root, INT_MIN, INT_MAX, s);

    cout << s.parentA->data << "  " <<s.parentB->data << endl;
    
    if(s.childA && s.childB)
    {
        Node* temp = s.parentA->right;
        s.parentA->right = s.parentB->right;
        s.parentB->right = temp;
    }
    else if(!s.childA && !s.childB)
    {
        Node* temp = s.parentA->left;
        s.parentA->left = s.parentB->left;
        s.parentB->left = temp;
    }
    else if(s.childA && !s.childB)
    {
        Node* temp = s.parentA->right;
        s.parentA->right = s.parentB->left;
        s.parentB->left = temp;
    }
     else if(!s.childA && s.childB)
    {
        Node* temp = s.parentA->left;
        s.parentA->left = s.parentB->right;
        s.parentB->right = temp;
    }
     inorder(root); cout <<endl;
    return 0;    
}