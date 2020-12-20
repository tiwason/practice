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

void swapNodes(Node** head, int x, int y)
{
    Node *prevX = NULL, *prevY = NULL, *prev = NULL;
    Node *temp = *head;
    Node *nodeX=NULL, *nodeY = NULL;
    int found = 0;

    while(temp != NULL)
    {
        if(temp->data == x)
        {
            prevX = prev;
            nodeX = temp;
            found++;
        }
        if(temp->data == y)
        { 
            prevY = prev;
            nodeY = temp;
            found++;
        }

        if(found == 2)
            break;

        prev = temp;
        temp = temp->next;
    }

    temp = nodeY->next;
    nodeY->next = nodeX->next;
    nodeX->next = temp;                                                                                                                                                                                                                                   
    
    if (prevX == NULL)
    {
        *head = nodeY;
        prevY->next = nodeX;
    }
    else if(prevY == NULL)
    {
        *head = nodeX;
         prevX->next = nodeY;
    }
    else
    {
        prevX->next = nodeY;
        prevY->next = nodeX;
    }   

}


int main()
{
    Node* head = NULL;
    push(&head, 10); 
    push(&head, 15); 
    push(&head, 12); 
    push(&head, 13);
    push(&head, 20);
    push(&head, 14);

    printLinkedList(head);
    swapNodes(&head, 14, 12);
    printLinkedList(head);
}
