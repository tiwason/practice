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

struct Info
{
    int sz;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root)
{
    if(root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    
    if(isLeafNode(root))
        return {1, root->data, root->data, 1, true};
    
    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    if (l.isBST && r.isBST && root->data > l.max && root->data < r.max)
    {   
        Info ret;
        ret.sz = l.sz + r.sz + 1;
        ret.min = min(l.min, min(r.min, root->data)); 
        ret.max = max(r.max, max(l.max, root->data));
        ret.ans = ret.sz;
        ret.isBST = true;
        return ret;
    }

    return (l.ans > r.ans ? l : r);
}

int main()
{
    Node *root = getNewTreeNode(5); 
    root->left = getNewTreeNode(2);
    root->right = getNewTreeNode(4);
    root->left->left = getNewTreeNode(1);
    root->left->right = getNewTreeNode(3);

    cout << largestBST(root).ans << endl;
    
    return 0;    
}