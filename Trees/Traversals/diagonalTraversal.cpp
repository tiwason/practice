#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef map<int, vector<int> > mv;

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

void diagonalTraversal(Node* node, int level, mv& diagonalMap)
{
    if(node == NULL)
        return;
    
    diagonalMap[level].push_back(node->data);
    diagonalTraversal(node->left, level+1, diagonalMap);
    diagonalTraversal(node->right, level, diagonalMap);
}


int main()
{
    Node* root = getNewTreeNode(8);
    Node* rootLeft = getNewTreeNode(3);
    Node* rootRight = getNewTreeNode(10);
    Node* rootLeftLeft = getNewTreeNode(1);
    Node* rootRightLeft = getNewTreeNode(6);
    Node* rootRightRight = getNewTreeNode(14);
    Node* rootRightRightLeft = getNewTreeNode(13);
    Node* rootRightLeftLeft = getNewTreeNode(4);
    Node* rootRightLeftRight =  getNewTreeNode(7);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootRight->left = rootRightLeft;
    rootRight->right = rootRightRight;
    rootRightRight->left = rootRightRightLeft;
    rootRightLeft->left = rootRightLeftLeft;
    rootRightLeft->right = rootRightLeftRight;

    mv diagonalMap;
    diagonalTraversal(root, 0, diagonalMap);
    for(auto e : diagonalMap)
    {
        for(auto v : e.second)
        {
            cout << v <<" ";
        }
        cout <<endl;
    }

    return 0;
}