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

int main()
{
    Node *head = NULL;
    
    push(&head, 6); 
    push(&head, 4); 
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printLinkedList(head);
   
}
