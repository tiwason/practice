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

ExpTreeNode* getNewExprNode(char data)
{
    ExpTreeNode* node = new ExpTreeNode();
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int evaluate(int a, int b, char c)
{
    switch(c)
    {
       case '+' : return a+b;
       case '-' : return a-b;
       case '*' : return a*b;
       case '/' : return a/b;
       case '^' : return a^b;
    }
}

int evaluateExprTree(ExpTreeNode* node)
{
    int result = 0;
    if(node)
    {
        if (isOperator(node->data))
        {
            int leftRes = evaluateExprTree(node->left);
            int rightRes = evaluateExprTree(node->right);
            result = evaluate(leftRes, rightRes, node->data);
        }
        else      
            return (node->data - '0');
    }
    return result;
}

int main()
{
    ExpTreeNode* root = getNewExprNode('+');
    ExpTreeNode* rootLeft = getNewExprNode('*');
    ExpTreeNode* rootRight = getNewExprNode('-');
    ExpTreeNode* rootLeftLeft = getNewExprNode('5');
    ExpTreeNode* rootLeftRight = getNewExprNode('4');
    ExpTreeNode* rootRightLeft = getNewExprNode('6');
    ExpTreeNode* rootRightRight = getNewExprNode('2');

    root->left = rootLeft;
    root->right = rootRight;
    rootLeft->left = rootLeftLeft;
    rootLeft->right = rootLeftRight;
    rootRight->left = rootRightLeft;
    rootRight->right = rootRightRight;

    cout << evaluateExprTree(root) <<endl;
    
    return 0;
}
