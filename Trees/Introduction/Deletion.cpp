#include <iostream>
#include <vector>
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

void deleteNode(Node* root, Node* node)
{
    queue<Node*> queue;
    queue.push(root);

    while(!queue.empty())
    {
        Node* temp = queue.front();
        queue.pop();

        if(temp == node)
        {
            temp == NULL;
            delete node;
            return;
        }

        if(temp->right)
        {
            if(temp->right == node)
            {
                temp->right = NULL;
                delete node;
                return;
            }else
                queue.push(temp->right);
        }
          
        if(temp->left)
        {
            if(temp->left == node)
            {
                temp->left = NULL;
                delete node;
                return;
            }else
                queue.push(temp->left);
        }
    }

}

void deleteKey(Node** root, int key)
{
    if(root == NULL)
        return;
    
    queue< Node* > queue;
    Node *temp=NULL, *keyNode=NULL;
    queue.push(*root);

    while(!queue.empty())
    {
        temp = queue.front();

        if(temp->data==key)
            keyNode = temp;
        if(temp->left)
            queue.push(temp->left);
        if(temp->right)
            queue.push(temp->right);
      
        queue.pop();
    }
    if(keyNode != NULL)
    {
        if(keyNode == temp)
        {
            *root = NULL;
            delete keyNode;
        } else
        {
            keyNode->data = temp->data;
            deleteNode(*root, temp);
        }
    }    
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
    bfsTreeTraversal(root); cout <<endl;

    deleteKey(&root, 2);
    dfsTreeTraversal(root); cout <<endl;
    bfsTreeTraversal(root); cout <<endl;
}