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

void removeDuplicates(Node** head)
{
    unordered_set<int> hash;
    Node* current = *head;
    Node*next=NULL;

    if(*head == NULL)
        return;
    
    while(current != NULL)
    {
        if(hash.find(current->data) != hash.end())
        {
            next = current->next;
            deleteNode(head, current);
            current = next;
        }
        else
        {
            hash.insert(current->data);
            current = current->next;
        }
    }
}


int main()
{
    Node *head = NULL;
    
    push(&head, 12); 
    push(&head, 12); 
    push(&head, 10);
    push(&head, 4);
    push(&head, 8);
    push(&head, 4);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 8);

    printLinkedList(head);
    removeDuplicates(&head);
    printLinkedList(head);
}
