#include <iostream>
#include "Stack_Class.cpp"
using namespace std;

// Class is declared in "Stack_Class.cpp" file name in this folder only.

int main()
{
    // creating the stack object.
    Stack s(5);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "size of stack -> " << s.total_size() << endl;

    s.push(5);
    s.push(6);
    // s.push(6); // if this get pushed then stack overflow happen as, the size we allocate is 5 only.
    cout << "size of stack -> " << s.total_size() << endl;
    // using the stack functions.
    cout << "top element -> " << s.top_data() << endl;
    s.pop();
    cout << "top element -> " << s.top_data() << endl;
    s.pop();
    cout << "top element -> " << s.top_data() << endl;
    s.pop();
    cout << "top element -> " << s.top_data() << endl;
    s.pop();
    cout << "top element -> " << s.top_data() << endl;
    s.pop();

    cout << "current size after pop -> " << s.total_size() << endl;

    cout << "empty or not -> " << s.empty() << endl;

    return 0;
}