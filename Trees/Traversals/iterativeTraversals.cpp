#include <iostream>
#include <vector>
#include <stack>

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

void preorderTraversal(Node* node)
{
    if(node == NULL)
        return;
    
    cout << node->data <<" ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void preorderIterativeTrav(Node* node)
{
    //node left right
    stack<Node*> s;
    Node* curr = node;

    while(curr || !s.empty())
    {
        while(curr)
        {
            cout << curr->data<<" ";
            if(curr->right)
                s.push(curr->right);
            curr = curr->left;
        }

       
        //curr is null here
        if(!s.empty())
        {
            curr = s.top();
            s.pop();

            if (curr)
            {
                cout << curr->data <<" ";
                curr = curr->left;
            }
        }       
    }
}

void inorderTraversal(Node* node)
{
    if(node == NULL)
        return;
    
    inorderTraversal(node->left);
    cout<<node->data<<" ";
    inorderTraversal(node->right);
}

void inorderIterativeTrav(Node* node)
{//left root right
    if (node == NULL)
        return;

    Node* curr = node;
    stack< Node* > s;

    while(curr!=NULL || !s.empty())
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        //Now curr is null, leftmost node
        curr = s.top();
        s.pop();
        cout << curr->data <<" ";

        curr = curr->right;
    }
}

void postorderTraversal(Node* node)
{
    if(node == NULL)
        return;
    
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout <<node->data<<" ";
}

void postorderIterativeTrav(Node* node)
{// left right root
    if(node == NULL)
        return;

    Node* curr=node;
    stack<Node*> s;

    while(curr || !s.empty())
    {
        while(curr)
        {   
            if (curr->right)
                s.push(curr->right);

            s.push(curr);           
            curr = curr->left;
        }
        // curr is NULL
        if (!s.empty())
        {
            curr = s.top();
            s.pop();

            if (!s.empty() && curr->right==s.top()) 
            {
                s.pop();
                s.push(curr);
                curr = curr->right;
            }
            else
            {
                cout << curr->data <<" ";
                curr = NULL;
            }            
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
    cout <<"preorder: "; preorderTraversal(root); cout <<endl;
    cout <<"inorder: "; inorderTraversal(root); cout<<endl;
    cout <<"postorder: "; postorderTraversal(root); cout<<endl;

    cout <<endl <<"Iterative traversals" <<endl;
    cout <<"inorder: "; inorderIterativeTrav(root); cout<<endl;
    cout <<"preorder: "; preorderIterativeTrav(root); cout<<endl;
    cout <<"postorder: "; postorderIterativeTrav(root); cout<<endl;
}