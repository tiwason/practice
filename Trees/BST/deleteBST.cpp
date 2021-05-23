#include <iostream>

using namespace std;

class BST
{
    int data;
    BST* left;
    BST* right;

    public:
        BST():data(0), left(NULL), right(NULL) {}
        BST(int key)
        {
            data = key;
            left = right = NULL;
        }

        BST* insert(BST* root, int data);
        BST* deleteNode(BST* root, int key);
        void inorder(BST* root);
        BST* findNextGreater(BST* root);
};

BST* BST::insert(BST* root, int data)
{
    if (root == NULL)
        return (new BST(data));
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;    
}

BST* BST::findNextGreater(BST* root)
{
    BST* curr = root;
    while(curr && curr->left)
        curr = curr->left;
    
    return curr;
}

//delete leaf node
//replace single child for the node
//replace with inorder successor for the node
BST* BST::deleteNode(BST* root, int data)
{
    if(root == NULL)
        return root;
    
    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else // found the key
    {
        if (root->left == NULL)
        {
            BST* temp = root->right;
            delete(root);
            return temp;
        }
        
        if(root->right == NULL)
        {
            BST* temp = root->left;
            delete(root);
            return temp;
        }
       
        BST * temp = findNextGreater(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::inorder(BST* root)
{
    if (root == NULL)
        return;
    
    inorder(root->left);
    cout <<root->data << " ";
    inorder(root->right);
}

int main()
{
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.inorder(root);
    cout << endl;

    b.deleteNode(root, 20);
    b.inorder(root);
    cout << endl;

    b.deleteNode(root, 30);
    b.inorder(root);
    cout << endl;
   
    root = b.deleteNode(root, 50);
    b.inorder(root);
    cout << endl;
    return 0;
}