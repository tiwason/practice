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

Node* reverseRecur(Node* curr, Node* prev)
{
    if (curr == NULL)
        return prev;
    
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    return reverseRecur(curr, prev);
}

void reverseIter(Node** head_ref)
{
    Node *curr, *prev, *next;

    if (*head_ref == NULL)
        return;
    
    curr = *head_ref;
    prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head_ref = prev;
}

int main()
{
    Node* head = NULL;
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4);
    push(&head, 5);

    printLinkedList(head);
    head = reverseRecur(head, NULL);
    printLinkedList(head);

    reverseIter(&head);
    printLinkedList(head);
}
