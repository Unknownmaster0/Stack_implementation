/*
initially the stack is -> 40 30 20 10
finally after insertion 50 at bottom -> 40 30 20 10 50

use the same logic used in deleting the middle element of the stack.
You can do this in both way iteratively or recursively . Showed the approch in deleting middle element question.
*/

#include <iostream>
#include <stack>
using namespace std;

// Note -> you can also do this in iterative way.

void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(num);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    int num;
    cout << "enter number to insert-> " << endl;
    cin >> num;
    insertAtBottom(s, num);

    cout << "printing stack after coming from the function -> ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}