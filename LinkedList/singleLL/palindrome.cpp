#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printLinkedList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout <<" NULL "<<endl;
}

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

bool checkPalindromeUtil(Node** start, Node* end)
{
    if (end == NULL)
        return true;
  

    bool res = checkPalindromeUtil(start, end->next);
    if (!res)
        return false;
    
    res = res && ((*start)->data == end->data);
    *start = (*start)->next;

    return res;
}

bool checkPalindrome(Node* head)
{
    return checkPalindromeUtil(&head, head->next);
}

int main()
{
    Node* head = NULL;
    push(&head, 1); 
    push(&head, 8); 
    push(&head, 3); 
    push(&head, 2);
    push(&head, 1);

    if (checkPalindrome(head))
        cout <<"linked list is palindrome"<<endl;
    else
    {
        cout <<"Linked list is not palindrome"<<endl;
    }
    
}
