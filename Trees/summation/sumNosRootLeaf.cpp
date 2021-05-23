#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <sstream>

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

void findRoottoLeafNos(Node* root, string pathNum, vector<string>& nos)
{
    if (root == NULL)
        return;
    
    pathNum += to_string(root->data);
    if (isLeafNode(root))
        nos.push_back(pathNum);
    
    findRoottoLeafNos(root->left, pathNum, nos);
    findRoottoLeafNos(root->right, pathNum, nos);
}

int main()
{
    Node *root = getNewTreeNode(6); 
    root->left = getNewTreeNode(3);
    root->right = getNewTreeNode(5);
    root->left->left = getNewTreeNode(2);
    root->left->right = getNewTreeNode(5);
    root->right->right = getNewTreeNode(4);
    root->left->right->left = getNewTreeNode(7);
    root->left->right->right = getNewTreeNode(4);
      
    vector<string> nos;
    findRoottoLeafNos(root, "", nos);

    int sum=0;
    for(auto &e : nos)
    {
        stringstream s(e);
        int num;
        s >> num;
        cout << num << " ";
        sum += num;
    }
    
    cout << endl << "Sum : "<< sum <<endl;
    return 0;
}