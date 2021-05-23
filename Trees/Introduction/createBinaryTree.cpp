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

void dfsTreeTraversal(Node* node)
{
    if(node == NULL)
        return;
    
    cout<<node->data << " ";
    dfsTreeTraversal(node->left);
    dfsTreeTraversal(node->right);
}

void bfsTreeTraversal(Node* node)
{
    vector< Node* > queue;
    queue.push_back(node);

    while(!queue.empty())
    {
        Node* frontNode = queue.front();

        if(frontNode->left)
            queue.push_back(frontNode->left);
        if(frontNode->right)
            queue.push_back(frontNode->right);
      
        cout << frontNode->data << " ";
        queue.erase(queue.begin());
    }
    cout <<endl;
}

int main()
{
    Node* root = getNewTreeNode(1);
    Node* rootLeft = getNewTreeNode(2);
    Node* rootRight = getNewTreeNode(3);
    Node* rootLeftLeft = getNewTreeNode(4);
    Node* rootLeftRight = getNewTreeNode(5);
    Node* rootRightLeft = getNewTreeNode(6);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootLeft->right = rootLeftRight;
    rootRight->left = rootRightLeft;

    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root);
}