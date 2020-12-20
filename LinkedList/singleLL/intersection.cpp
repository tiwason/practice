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

Node* intersectionLL(Node* mem1, Node* mem2)
{
    if (mem1 == NULL || mem2 == NULL)
        return NULL;
    
    if (mem1->data == mem2->data)
    {
        Node* newNode = new Node();
        newNode->data = mem1->data;
        newNode->next = intersectionLL(mem1->next, mem2->next);
        return newNode;
    }
    else if(mem1->data < mem2->data)
        return intersectionLL(mem1->next, mem2);
    else
        return intersectionLL(mem1, mem2->next);    
}


int main()
{
    Node *head1 = NULL, *head2 = NULL;
    
    push(&head1, 6); 
    push(&head1, 4); 
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);

    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 2);

    printLinkedList(head1);
    printLinkedList(head2);
    printLinkedList(intersectionLL(head1, head2));
}
