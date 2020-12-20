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

void findPairs(Node* head, int sum)
{
    Node *first = head, *last = NULL, *temp = head;

    if (!head)
        return;

    while(temp->next != NULL)
        temp = temp->next;
    
    last = temp;

    while(first != last)
    {
        if((first->data + last->data) > sum)
            last = last->prev;
        else if ((first->data + last->data) < sum)
            first = first->next;
        else
        {
            cout << first->data  <<"  " <<last->data<<endl;
            first = first->next;
            last = last->prev;
        }        
    }
}

int main()
{
    Node *head = NULL;
    
    push(&head, 9); 
    push(&head, 8); 
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);

    findPairs(head, 7);
}
