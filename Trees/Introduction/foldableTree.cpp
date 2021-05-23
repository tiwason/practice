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

bool isLeafNode(Node* node)
{
    return (node->left == NULL && node->right == NULL);
}

bool isFoldableUtil(Node* leftSubtree, Node* rightSubtree)
{
    if (leftSubtree == NULL && rightSubtree == NULL)
        return true;
    else if(leftSubtree != NULL && rightSubtree != NULL)
    {
        if (leftSubtree->left && rightSubtree->right)
            return isFoldableUtil(leftSubtree->left, rightSubtree->right);
        else if (leftSubtree->right && rightSubtree->left)
            return isFoldableUtil(leftSubtree->right, rightSubtree->left);
        else if (isLeafNode(leftSubtree) && isLeafNode(rightSubtree))
            return true;
        else
            return false;        
    }
    else
        return false;
}

bool isFoldable(Node* root)
{
    if (root == NULL)
        return true;
    
    if (root->left && root->right)
        return isFoldableUtil(root->left, root->right);
    else
        return false;  
}

int main()
{
    Node* root = getNewTreeNode(10);
    Node* rootLeft = getNewTreeNode(7);
    Node* rootRight = getNewTreeNode(15);
    Node* rootLeftRight = getNewTreeNode(9);
    Node* rootRightLeft = getNewTreeNode(11);

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->right = rootLeftRight;
    rootRight->left = rootRightLeft;

    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root);

    if(isFoldable(root))
        cout<< "tree is foldable"<<endl;
    else
        cout <<"tree is not foldable"<<endl;
    
}