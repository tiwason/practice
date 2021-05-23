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

void findAddition(Node* head1, Node* head2)
{
    Node *last1=head1, *last2=head2;
  
    if(head1 == NULL || head2 == NULL)
        return;

    while(last1->next != NULL)
        last1 = last1->next;
    
    while(last2->next != NULL)
        last2 = last2->next;
    
    //create result Linked list
    Node* result = NULL;
    int carry = 0;

    while(last1 && last2)
    {
        int sum = last1->data + last2->data + carry;
        carry = sum/10;
        sum = sum%10;
        push(&result, sum);

        last1 = last1->prev;
        last2 = last2->prev;
    }

    while(last1 != NULL)
    {
        int sum = last1->data + carry;
        carry = sum/10;
        sum = sum%10;
        push(&result, sum);
        last1 = last1->prev;
    }

     while(last2 != NULL)
    {
        int sum = last2->data + carry;
        carry = sum/10;
        sum = sum%10;
        push(&result, sum);
        last2 = last2->prev;
    }

    printLinkedList(result);
}


int main()
{
    int m = 55, n = 6;
    Node *headLL1 = NULL, *headLL2 = NULL;
    
    int temp = m;
    while(temp != 0) //convert to LinkedList
    {
        push(&headLL1, temp%10);
        temp = temp/10;
    }

    temp = n;
    while(temp != 0) //convert to LinkedList
    {
        push(&headLL2, temp%10);
        temp = temp/10;
    }
   
    printLinkedList(headLL1);
    printLinkedList(headLL2);
    findAddition(headLL1, headLL2);

    return 0;
}
