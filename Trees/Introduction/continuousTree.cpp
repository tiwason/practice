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

bool isContinuous(Node* node)
{
    if (node == NULL)
        return true;
    
    if(node->left && abs(node->data - node->left->data)!=1)
        return false;
    
     if(node->right && abs(node->data - node->right->data)!=1)
        return false;

    return (isContinuous(node->left) && isContinuous(node->right));
}

int main()
{
    Node* root = getNewTreeNode(3);
    Node* rootLeft = getNewTreeNode(2);
    Node* rootRight = getNewTreeNode(4);
    Node* rootLeftLeft = getNewTreeNode(1);
    Node* rootLeftRight = getNewTreeNode(3);
    Node* rootRightRight = getNewTreeNode(5);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootLeft->right = rootLeftRight;
    rootRight->right = rootRightRight;

    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root);

    if(isContinuous(root))
        cout<< "tree is continuous"<<endl;
    else
        cout <<"tree is not continuous"<<endl;
    
}