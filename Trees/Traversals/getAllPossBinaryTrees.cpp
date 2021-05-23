#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* getNewNode(int data)
{
    node* n = new node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void printArray(int arr[], int start, int end)
{
    for(int i=start; i<= end; i++)
        cout <<arr[i]<<" ";
    cout<<endl;
}

void preorderTrav(node* root)
{
    if(root==NULL)
        return;
    
    cout << root->data <<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

vector<node*> getTrees(int inorder[], int start, int end)
{
    vector<node*> trees;

    if(start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++)
    {
        vector<node*> leftTrees = getTrees(inorder, start, i-1);
        vector<node*> rightTrees = getTrees(inorder, i+1, end);

        for(int j = 0; j<leftTrees.size(); j++)
        {
            for(int k =0; k<rightTrees.size(); k++)
            {
                node* root = getNewNode(inorder[i]);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                trees.push_back(root);
            }
        }
    }   
    return trees;
}

int main()
{
    int inorder[] = {3, 2};
    //int inorder[] = {4, 5, 7};
    int size = sizeof(inorder)/sizeof(inorder[0]);
    
    vector<node*> trees = getTrees(inorder, 0, size-1);
    for(auto t: trees)
    {
        preorderTrav(t);
        cout<<endl;
    }
   
    return 0;
}
