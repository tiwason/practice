#include <iostream>
#include <queue>

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
    queue< Node* > queue;
    queue.push(node);

    while(!queue.empty())
    {
        Node* frontNode = queue.front();

        if(frontNode->left)
            queue.push(frontNode->left);
        if(frontNode->right)
            queue.push(frontNode->right);
      
        cout << frontNode->data << " ";
        queue.pop();
    }
    cout <<endl;
}

void insertInLevelOrder(Node** root, int data)
{
    if(*root == NULL)
    {
        *root = getNewTreeNode(data);
        return;
    }

    queue< Node* > queue;
    queue.push(*root);
    Node* newNode = getNewTreeNode(data);

    while(!queue.empty())
    {
        Node* frontNode = queue.front();

        if(frontNode->left)
            queue.push(frontNode->left);
        else
        {
            frontNode->left = newNode;
            return;
        }
        
        if(frontNode->right)
            queue.push(frontNode->right);
        else
        {
            frontNode->right = newNode;
            return;
        }
        queue.pop();
    }
}

int main()
{
    Node* root = getNewTreeNode(10);
    Node* rootLeft = getNewTreeNode(11);
    Node* rootRight = getNewTreeNode(9);
    Node* rootLeftLeft = getNewTreeNode(7);
    
    Node* rootRightLeft = getNewTreeNode(15);
    Node* rootRightRight = getNewTreeNode(8);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootRight->left = rootRightLeft;
    rootRight->right = rootRightRight;

    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root);

    insertInLevelOrder(&root, 12);cout <<endl;
    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root);
}