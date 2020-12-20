#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

int countNodes(Node* node)
{
    int res = 1;
    Node* temp = node;

    while(temp->next != node)
    {
        res++;
        temp = temp->next;
    }

    return res;
}

int findAndCountLoop(Node* head)
{
    Node *slow, *fast;
    int count = 0;

    if(head)
    {
        slow = head;
        fast = head->next;
        Node* loopNode = NULL;

        while(slow && fast && fast->next)
        {
            if (slow == fast)
                return countNodes(slow);
              
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return 0;
}

int main()
{
    Node* head = NULL;
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10);

    //head->next->next->next->next = head;

    cout << "Loop Size : "<< findAndCountLoop(head) <<endl;
}
