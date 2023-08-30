#include <iostream>
#include <stack>
using namespace std;

// Time complexity -> O(n) n is the number of element in the stack
// Space complexity -> O(n/2) = O(n) size of stack.

/*
void removingMiddle(stack<int>&s , int n)
{
    int* arr = new int[n/2];
    int i = 0;
    for(; i<n/2; i++)
    {
        arr[i] = s.top();
        s.pop();
    }

    s.pop(); // removing the middle element.

    // Again pushing the popped element above the middle
    for(int i = n/2 -1; i >= 0; i--)
    {
        s.push(arr[i]);
    }

    return;
}

*/

void solve(stack<int> &s, int itr, int size)
{
    if (itr == size / 2 + 1)
    {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, itr + 1, size);
    s.push(num);
}

void deleteMiddle(stack<int> &s, int size)
{
    int itr = 1; // iterator.
    solve(s, itr, size);
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    // s.push(5);

    // in printing the stack before, we had popped all elements in the stack then it will give error.
    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop(); // this line
    // }
    // cout << endl;

    deleteMiddle(s, s.size());

    cout << "stack after deleting -> " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}