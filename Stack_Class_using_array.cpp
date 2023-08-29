#include <iostream>
using namespace std;

// Array implementataion of the Stack.
/*
    concept -> we are going to create our own stack, which have push, pop , top , empty and size function.
                We need the three thing to implement this using the array.
                1. array.
                2. size of array.
                3. iterator to iterate over the array , ex -> top.

                initially we initialise top = -1;
                size of array is given by user as input.
*/

class Stack
{
private:
    int *arr; // dynamically create the array.
    int size; // used for checking the size and dynamically allocating the space to the array.
    int top;  // variable for traversing the array.

public:
    // making the constructor.
    Stack(int size)
    {
        this->size = size;
        arr = new int[size]; // dynamically array implementation.
        top = -1;            // initialising the top variable.
    }

    void push(int data)
    {
        // if condition true means -> we have atleast one space vacant.
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "stack overflow. " << endl;
            exit(1);
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow." << endl;
            return;
        }

        // for pop back the element means we decrement the top iterator.
        top--;
    }

    int top_data()
    {
        if (top == -1) // empty stack
        {
            cout << "empty stack -> ";
            exit(1);
            return -1;
        }
        if (top >= size)
        {
            cout << "stack overflow." << endl;
            exit(1);
            return -1;
        }
        return arr[top];
    }

    int total_size()
    {
        if (top == -1)
        {
            cout << "stack is empty"
                 << " -> ";
            return 0;
        }

        if (top >= size)
        {
            cout << "stack overflow." << endl;
            exit(1);
            return -1;
        }

        return top + 1;
    }

    bool empty()
    {
        // when top is at -1 , that is at initial position means no element is inserted in the stack.
        if (top == -1)
            return true;

        else
            return false;
    }
};
