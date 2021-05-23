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

    if(!head)
    {
        cout <<"Empty Circular Linked List" <<endl;
        return;
    }
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

void deleteCLL(Node** head, int key)
{
    if (*head == NULL)
        return;
    
    //find the node to be deleted in CLL
    Node *temp = *head, *prev = NULL;
    while (temp->data != key && temp->next != *head)
    {   prev = temp;
        temp = temp->next;
    }
    
    if(temp->data != key)
    {
        cout <<"data to be deleted not found in CLL" <<endl;
        return;
    }
    else
    {
        if(temp == *head) //first element and only element
        {   
             //find the last element
            Node *last = *head;
            while(last->next != *head)
                last = last->next;

            if(temp->next != temp)
            {
                last->next = temp->next;
                *head = temp->next;
            } else
                *head = NULL;          
        }
        else
        {   
            prev->next = temp->next;
        }

        delete temp;
    }

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
    deleteCLL(&head, 1);
    printLinkedList(head);
    deleteCLL(&head, 6);
    printLinkedList(head);
    deleteCLL(&head, 4);
    printLinkedList(head);
    deleteCLL(&head, 3);
    printLinkedList(head);
    deleteCLL(&head, 2);
    printLinkedList(head);
    deleteCLL(&head, 5);
    printLinkedList(head);
}
