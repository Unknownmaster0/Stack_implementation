#include <iostream>
#include <stack>
using namespace std;

/*
Concept -> 1. first traversing the stack only using recursion and just storing the top element every time.
           2. Now when the stack becomes empty -> just return;
           3. After going back from the recusive call or after return, simply push the element in stack in sorted order using function sort
           4. in sort function we have some condition ->
           5. if the number to insert(num) in the stack is greater then the top element of the stack, then simply insert the num.
           6. if the number to insert in the stack is less then the top element, then store that top element.
           7. until you find the element less than num or stack is empty,
                 and when this condition reaches, simply push the num.
*/

void sort(stack<int> &s, int num)
{
    // 5. if the number to insert(num) in the stack is greater then the top element of the stack, then simply insert the num.
    if (s.empty() || s.top() <= num)
    {
        s.push(num);
        return;
    }

    int store;
    // 6. if the number to insert in the stack is less then the top element, then store that top element.
    // 7. until you find the element less than num or stack is empty,
    //  and when this condition reaches, simply push the num.
    if (num < s.top())
    {
        store = s.top();
        s.pop();
    }

    // recursive call.
    sort(s, num);

/*  this can be also written for the above thing.
    int store = s.top();
    s.pop();
    
    sort(s,num);
*/

    s.push(store);
}

// 1. first traversing the stack only using recursion and just storing the top element every time.
void traverse(stack<int> &s)
{
    // 2. Now when the stack becomes empty -> just return;
    if (s.empty())
        return;

    int num = s.top();
    s.pop();
    traverse(s);
    // 3. After going back from the recusive call or after return, simply push the element in stack in sorted order using function sort
    sort(s, num);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(-4);
    s.push(3);
    s.push(3);
    s.push(7);
    s.push(-10);
    s.push(-10);

    traverse(s);

    cout << "printing the stack after coming from the function." << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}