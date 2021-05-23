#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printSpecificLevelOrder(Node* node)
{
    queue< Node* > q;

    cout << node->data <<" ";
    if(node->left)
        q.push(node->left);
    if(node->right)
        q.push(node->right);

    while(!q.empty())
    {
        Node* Node1 = q.front(); q.pop();
        Node* Node2 = q.front(); q.pop();

        if(Node1->left && Node2->right)
        {
            q.push(Node1->left);
            q.push(Node2->right);
        }
        if(Node1->right && Node2->left)
        {
            q.push(Node1->right);
            q.push(Node2->left);
        }
        cout << Node1->data << " " <<Node2->data << " ";
    }
    cout <<endl;
}




int main()
{
    Node *root = newNode(1); 
  
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    root->left->left->left  = newNode(8); 
    root->left->left->right  = newNode(9); 
    root->left->right->left  = newNode(10); 
    root->left->right->right  = newNode(11); 
    root->right->left->left  = newNode(12); 
    root->right->left->right  = newNode(13); 
    root->right->right->left  = newNode(14); 
    root->right->right->right  = newNode(15); 
  
    root->left->left->left->left  = newNode(16); 
    root->left->left->left->right  = newNode(17); 
    root->left->left->right->left  = newNode(18); 
    root->left->left->right->right  = newNode(19); 
    root->left->right->left->left  = newNode(20); 
    root->left->right->left->right  = newNode(21); 
    root->left->right->right->left  = newNode(22); 
    root->left->right->right->right  = newNode(23); 
    root->right->left->left->left  = newNode(24); 
    root->right->left->left->right  = newNode(25); 
    root->right->left->right->left  = newNode(26); 
    root->right->left->right->right  = newNode(27); 
    root->right->right->left->left  = newNode(28); 
    root->right->right->left->right  = newNode(29); 
    root->right->right->right->left  = newNode(30); 
    root->right->right->right->right  = newNode(31); 

    printSpecificLevelOrder(root);
    cout<<endl;
    return 0;
}