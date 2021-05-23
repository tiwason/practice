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
        void inorder(BST* root);
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

    return 0;
}