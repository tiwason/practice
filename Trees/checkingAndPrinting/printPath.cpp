#include <iostream>
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

void printVector(vector<int> path)
{
    for (auto& e : path)
        cout << e <<" -> ";
    cout << " NULL" <<endl;
}

void printPath(Node* root, int data, vector<int> path)
{
    if(root == NULL)
        return;
    
    if(root->data == data)
    {
        path.push_back(data);
        printVector(path);
        return;
    }
    path.push_back(root->data);
    printPath(root->left, data, path);
    printPath(root->right, data, path);
}

int main()
{
    Node *tree1 = getNewTreeNode(1); 
    tree1->left = getNewTreeNode(2); 
    tree1->right = getNewTreeNode(3);
    tree1->left->left = getNewTreeNode(4);
    tree1->left->right = getNewTreeNode(5);
    tree1->left->right->left = getNewTreeNode(6);
    tree1->left->right->right = getNewTreeNode(7);

    vector<int> path;
    printPath(tree1, 5, path);

    return 0;
}