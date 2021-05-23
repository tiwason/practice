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

bool findSubTreeWithSumK(Node* root, int k, int& sum)
{
    if (root != NULL)
    {
        int lsum=0, rsum=0;
        if(findSubTreeWithSumK(root->left, k, lsum))
            return true;
        if(findSubTreeWithSumK(root->right, k, rsum))
            return true;
        
        sum = lsum + rsum + root->data;

        if(sum == k)
            return true;
    }
    return false;
}

void printVector(vector<int>& vec)
{
    for(auto& e: vec)
        cout << e <<" ";
    cout <<endl;
}

int main()
{
    Node *root = getNewTreeNode(1); 
    root->left = getNewTreeNode(3);
    root->right = getNewTreeNode(6);
    root->left->left = getNewTreeNode(5);
    root->left->right = getNewTreeNode(9);
    root->right->left = getNewTreeNode(8);
  
    int sum=0;

    if(findSubTreeWithSumK(root, 9, sum))
        cout << "subtree found" <<endl;
    else
        cout << "No subtree found" <<endl;
    
    return 0;
}