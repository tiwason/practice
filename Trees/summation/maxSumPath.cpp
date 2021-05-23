#include <iostream>
#include <climits>
#include <deque>

using namespace std;

typedef deque<int> Path;

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

Path getMaxSumPath(Node* root, int sum, int& maxSum, Path pathV)
{
    if(root != NULL)
    {
        pathV.push_front(root->data);
        sum += root->data;

        if(isLeafNode(root))
        {
            maxSum = (maxSum < sum) ? sum : maxSum;
            return pathV;
        }

        int lsum = sum, rsum = sum;
        Path left = getMaxSumPath(root->left, lsum, maxSum, pathV);
        Path right = getMaxSumPath(root->right, rsum, maxSum, pathV);

        return ((lsum > rsum) ? left : right);
    }
    return pathV;
}

int main()
{
    Node* root = getNewTreeNode(10); 
    root->left = getNewTreeNode(-2); 
    root->right = getNewTreeNode(7); 
    root->left->left = getNewTreeNode(8); 
    root->left->right = getNewTreeNode(-4); 

    int maxSum = INT_MIN;
    Path pathV;
    pathV = getMaxSumPath(root, 0, maxSum, pathV);

    for(auto &e : pathV)
        cout << e << " ";
    cout<<endl;

    return 0;
}