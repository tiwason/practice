#include <iostream>

using namespace std;

struct Node
{
    int data;
    int priority;
    Node* next;
    Node* prev;
};

class priorityQueue
{
    public:
        priorityQueue() {head = NULL; tail = NULL;}
        ~priorityQueue() {};
        void push(Node** head_ref, int data, int priority);
        void pop(Node** head_ref);
        int top(Node* head_ref) const {return head->data;}
        bool isEmpty() {return !(head);}

    private:
        Node* head;
        Node* tail;        
};