#include <iostream>
#include <climits>
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

void printVector(vector<int>& vec, int i)
{
    for(int j = i; j < vec.size(); j++)
        cout << vec[j] <<" ";
    cout << endl;
}

void printKPath(Node* root, int k, vector<int>& path)
{
    if(root == NULL)
        return;

    path.push_back(root->data);

    printKPath(root->left, k, path);
    printKPath(root->right, k, path);

    int sum = 0;
    for(int i=path.size()-1; i >= 0; i--)
    {
        sum += path[i];
        if(sum == k)
            printVector(path, i);
    }
    path.pop_back();
}

int main()
{
    Node *root = getNewTreeNode(1); 
    root->left = getNewTreeNode(3); 
    root->left->left = getNewTreeNode(2); 
    root->left->right = getNewTreeNode(1); 
    root->left->right->left = getNewTreeNode(1); 
    root->right = getNewTreeNode(-1); 
    root->right->left = getNewTreeNode(4); 
    root->right->left->left = getNewTreeNode(1); 
    root->right->left->right = getNewTreeNode(2); 
    root->right->right = getNewTreeNode(5); 
    root->right->right->right = getNewTreeNode(2); 
  
    int k = 5;
    vector<int> path; 
    printKPath(root, k, path); 
  
    return 0;
}