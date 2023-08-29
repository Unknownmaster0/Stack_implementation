#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *top;
    int size;

public:
    // default constructor.
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        // when the heap memory is exhausted then, the 'temp' will point to NULL
        if (temp == NULL)
        {
            cout << "stack overflow." << endl;
            exit(1);
        }

        temp->next = top;

        top = temp;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow." << endl;
            exit(1);
        }

        top = top->next;
        size--;
    }

    bool empty()
    {
        // top is null means the stack is empty.
        if (top == NULL)
            return true;

        return false;
    }

    int top_data()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return (top->data);
    }

    int total_size()
    {
        return size;
    }
};