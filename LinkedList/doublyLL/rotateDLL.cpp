#include <iostream>
#include <unordered_set>

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

void deleteNode(struct Node** head_ref, struct Node* del) 
{ 
    if (*head_ref == NULL || del == NULL) 
        return; 
  
    if (*head_ref == del) 
        *head_ref = del->next; 
  
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    free(del); 
} 

void rotateDLL(Node** head_ref, int k)
{
    Node *last = *head_ref;
    int size = 0;

    if(*head_ref == NULL)
        return;
    
    while(last->next != NULL)
    {   
        last = last->next;
        size++;
    }

    if (k < size)
    {
        last->next = *head_ref;

        int moveBack = size - k;
        while(moveBack--)
            last = last->prev;
            
        last->prev->next = NULL;
        last->prev = NULL;
        *head_ref = last;
    }   
}

int main()
{
    Node *head = NULL;
    
    push(&head, 5); 
    push(&head, 4); 
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printLinkedList(head);
    rotateDLL(&head, 5);
    printLinkedList(head);
}
