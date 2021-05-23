#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct ExpTreeNode
{
    char data;
    ExpTreeNode* left;
    ExpTreeNode* right;
};

void inOrderTraversal(ExpTreeNode* node)
{
    if(node == NULL)
        return;
    
    inOrderTraversal(node->left);
    cout << node->data <<" ";
    inOrderTraversal(node->right);
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

ExpTreeNode* getNewExprNode(char data)
{
    ExpTreeNode* node = new ExpTreeNode();
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

ExpTreeNode* buildExpTree(string str)
{
    stack <ExpTreeNode*> S;

    for (auto c : str)
    {
        if (isOperator(c))
        {
            ExpTreeNode* opNode = getNewExprNode(c);
            opNode->right = S.top();
            S.pop();
            opNode->left = S.top();
            S.pop();
            S.push(opNode);
        }
        else
            S.push(getNewExprNode(c));
    }

    return S.top();
}

int main()
{
    string postfix = "ab+ef*g*-";
    ExpTreeNode* root = buildExpTree(postfix);

    inOrderTraversal(root);
    cout << endl;
    return 0;
}
