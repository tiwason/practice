#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* insertFirst(Node* head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertLast(Node* head, int data)
{
    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* insertAfter(Node* head, int data, int key)
{
    Node* temp = head;

    while(temp->data != key)
        temp = temp->next;
    
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

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

int main()
{
    Node* head = NULL;

    head = insertFirst(head, 5);
    head = insertFirst(head, 10);
    head = insertFirst(head, 15);
    head = insertFirst(head, 25);

    head = insertAfter(head, 20, 15);
    head = insertLast(head, 30);

    printLinkedList(head);
}
