#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
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

void printReverseLinkedList(Node* head)
{
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout <<" NULL "<<endl;
}

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = *head_ref;
    newNode->prev = NULL;

    if (*head_ref)
        (*head_ref)->prev = newNode;
    
    *head_ref = newNode;
}

void deleteNode(Node** head_ref, int data)
{
    Node* temp = *head_ref;

    while(temp && temp->data != data)
        temp = temp->next;
    
    if (temp->prev && temp->next)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else
    {
        if (temp->prev == NULL)
        {
            *head_ref = temp->next;
            temp->next->prev = NULL;
        }
        else
            temp->prev->next = NULL;
                
    }
   
    delete temp;
}

Node* reverseDLL(Node* node)
{
    if (!node)
        return NULL;
   
    Node* temp = node->next;
    node->next = node->prev;
    node->prev = temp;

    if (node->prev == NULL)
        return node;
    
    return reverseDLL(temp);
}

int main()
{
    Node *head = NULL;
    
    push(&head, 6); 
    push(&head, 5);
    push(&head, 4); 
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    head = reverseDLL(head);
    printLinkedList(head);
    printReverseLinkedList(head);

    cout << endl;
}
