#include <iostream>

using namespace std;

struct AVL_Node
{
    int data;
    int height;
    AVL_Node* left;
    AVL_Node* right;
};

AVL_Node* newAVLNode(int data)
{
    AVL_Node* node = new AVL_Node();
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

int getHeightDiff(AVL_Node* node)
{
    int leftSubTreeHeight = (node->left) ? node->left->height : 0;
    int rightSubTreeHeight = (node->right) ? node->right->height : 0;
    return (leftSubTreeHeight - rightSubTreeHeight);
}

int getHeight(AVL_Node* node)
{
    if(node == NULL)
        return 0;
    
    return node->height;
}

AVL_Node* leftRotate(AVL_Node* node)
{
    AVL_Node* rightNode = node->right;
    AVL_Node* leftChildOfRight = rightNode->left;

    rightNode->left = node;
    node->right = leftChildOfRight;
    
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightNode->height = max(getHeight(rightNode->left), getHeight(rightNode->right)) + 1;
    
    return rightNode;
}

AVL_Node* RightRotate(AVL_Node* node)
{
    AVL_Node* leftNode = node->left;
    AVL_Node* RightChildOfLeft = leftNode->right;

    leftNode->right = node;
    node->left = RightChildOfLeft;
    
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftNode->height = max(getHeight(leftNode->left), getHeight(leftNode->right)) + 1;
   
    return leftNode;    
}

AVL_Node* insert(AVL_Node* root, int data)
{
    if(root == NULL)
        return newAVLNode(data);
    
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    else
        return root;
    
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    int balanceFactor = getHeightDiff(root);

    //Left Left / Left right case
    if(balanceFactor > 1)
    {
        if(data < root->left->data)
            return RightRotate(root);
        else
        {
            root->left = leftRotate(root->left);
            return RightRotate(root);
        }     
    }
    else if(balanceFactor < -1) // right right / right left case
    {
        if(data > root->right->data)
            return leftRotate(root);
        else
        {
           root->right = RightRotate(root->right);
           return leftRotate(root);
        }     
    }

    return root;
}

void preOrderTraversal(AVL_Node* root)
{
    if(root == NULL)
        return;
    
    cout <<root->data <<" " << root->height <<endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

AVL_Node* getInorderSuccessor(AVL_Node* node)
{
    AVL_Node* curr = node;
    while(curr && curr->left)
        curr = curr->left;

    return curr;
}

AVL_Node* deleteKey(AVL_Node* node, int key)
{
    if(node == NULL)
        return node;
    
    if (key < node->data)
        node->left = deleteKey(node->left, key);
    else if (key > node->data)
        node->right = deleteKey(node->right, key);
    else
    {
        if(node->left == NULL) //only right child
        {
            AVL_Node* temp = node->right;
            node = NULL;
            delete node;
            return temp;
        }
        if(node->right == NULL) //only right child
        {
            AVL_Node* temp = node->left;
            node = NULL;
            delete node;
            return temp;
        }

        AVL_Node* temp = getInorderSuccessor(node->right);
        node->data = temp->data;
        node->right = deleteKey(node->right, temp->data);
    }

    node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
    int balanceFactor = getHeightDiff(node);

    //Left Left / Left right case
    if(balanceFactor > 1)
    {
        if(getHeightDiff(node->left) >= 0)
            return RightRotate(node);
        else
        {
            node->left = leftRotate(node->left);
            return RightRotate(node);
        }     
    }
    else if(balanceFactor < -1) // right right / right left case
    {
        if(getHeightDiff(node->right) <= 0)
            return leftRotate(node);
        else
        {
           node->right = RightRotate(node->right);
           return leftRotate(node);
        }     
    }
    
    return node;
}

int main()
{
    AVL_Node* root = newAVLNode(10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preOrderTraversal(root);
    cout << endl;

    root = deleteKey(root, 40);
    preOrderTraversal(root);
    cout << endl;

    root = deleteKey(root, 50);
    preOrderTraversal(root);
    cout << endl;

    root = deleteKey(root, 20);
    preOrderTraversal(root);
    cout << endl;

    return 0;
}