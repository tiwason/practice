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

void splitCLL(Node* head)
{
    Node *last = head, *mid = head;
    if(!head)
        return;
    //if even nodes last->next->next becomes head 
    while(last->next != head && last->next->next != head)
    {
        last = last->next->next;
        mid = mid->next;
    }

    if(last->next->next == head)
        last = last->next; //move to last pointer in case of even nodes
    
    Node *cll1 = head, *cll2 = mid->next;
    mid->next = cll1;
    last->next = cll2;
    printLinkedList(cll1);
    printLinkedList(cll2);
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
    splitCLL(head);
}
