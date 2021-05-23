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

void pushNode(Node** head_ref, Node* new_node) 
{ 
    // since we are adding at the beginning, 
    // prev is always NULL 
    new_node->prev = NULL; 
   
    // link the old list off the new node 
    new_node->next = (*head_ref); 
   
    // change prev of head node to new node 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
   
    // move the head to point to the new node 
    (*head_ref) = new_node; 
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

Node* reverse(Node* head, int k)
{
    Node *current = head; 
    Node* next = NULL; 
    Node* newHead = NULL; 
    int count = 0; 

    while(current && count < k)
    {
        next = current->next;
        pushNode(&newHead, current);
        current = next;
        count++;
    }

    if(next != NULL)
    {
        head->next = reverse(next, k);
        head->next->prev = head;
    }
    
    return newHead;
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


int main()
{
    Node *head = NULL;
    
    push(&head, 10); 
    push(&head, 8); 
    push(&head, 4);
    push(&head, 2);

    printLinkedList(head);
    head = reverse(head, 2);
    printLinkedList(head);
}
