/* In this question we normally going to reverse the stack elements.
    given stack -> 40 30 20 10
    answer stack -> 10 20 30 40
*/
#include <iostream>
#include <stack>

using namespace std;

// Note -> You can do this question both in iteratively and recursive way.
/* concept to reverse recursively ->
            1. first store the s.top() element.
            2. then pop that element.
            3. again call the function b/c in this way we can traverse the whole stack.
            4. After going from the recusion call, just do somethig different form deleting the middle or insert at bottom one.
                just insert the num stored at bottom by calling the function insert at bottom.
*/

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

void reverseStack(stack<int> &s)
{
    // means we have traversed the whole stack , then simply return , time to call the insert at bottom function.
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, num);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    reverseStack(s);

    cout << "stack after coming from the function is -> " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}