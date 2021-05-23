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
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);

    cout <<head->data <<endl;
}

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = (*head_ref==NULL) ? newNode : *head_ref;  

    if (*head_ref != NULL) //set next pointer of last node to newly created node
    {   Node* temp = *head_ref;
        while(temp->next != *head_ref)
            temp = temp->next;
        temp->next = newNode;
    }

    *head_ref = newNode;
}

void exchangeFirstLast(Node** head)
{
    Node *prev=NULL, *last=*head;

    if(*head==NULL || (*head)->next == *head) //0 or 1 element
        return;
    
    while(last->next != *head)
    {
        prev = last;
        last = last->next;
    }

    prev->next = *head;
    *head = last;
    last->next = prev->next->next;
    prev->next->next = *head;
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

    printLinkedList(head);
    exchangeFirstLast(&head);
    printLinkedList(head);
}
