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

bool isLeafNode(Node* tree)
{
    return (tree->left == NULL && tree->right == NULL);
}

void getDiagonalNodes(Node* tree, mv& dMap, int dist)
{
    if(tree == NULL)
        return;
    
    dMap[dist].push_back(tree->data);
    getDiagonalNodes(tree->left, dMap, dist+1);
    getDiagonalNodes(tree->right, dMap, dist);
}

int main()
{
    Node *tree1 = getNewTreeNode(1); 
    tree1->left = getNewTreeNode(2); 
    tree1->right = getNewTreeNode(3);
    tree1->left->left = getNewTreeNode(9);
    tree1->left->right = getNewTreeNode(6);
    tree1->right->left = getNewTreeNode(4);
    tree1->right->right = getNewTreeNode(5);
    tree1->left->left->right = getNewTreeNode(10);
    tree1->left->right->left = getNewTreeNode(11);
    tree1->right->left->left = getNewTreeNode(12);
    tree1->right->left->right = getNewTreeNode(7);
    
    mv dMap;
    getDiagonalNodes(tree1, dMap, 0);

    for(auto& p : dMap)
    {
        int sum = 0;
        for(auto& e : p.second)
            sum += e;
        cout << sum << endl;
    }

    return 0;
}