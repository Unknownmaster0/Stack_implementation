/*
Reverse the stack using the recursion in O(N * N)[time complexity] and O(1) space complexity
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// time complexity -> O(N* N) using the two recursion technique.
void insert(stack<int> &st, int n)
{
    if (st.empty())
    {
        st.push(n);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, n);
    st.push(top);
}

void Reverse(stack<int> &st)
{
    if (st.size() == 0)
        return;

    int top = st.top();
    st.pop();

    Reverse(st);

    insert(st, top);
}

int main()
{
    vector<int> v{4, 5, 7};
    // pushing the data in stack
    stack<int> st;
    for (auto i : v)
        st.push(i);
// now st contains -> 7 5 4

    // reversing the stack
    Reverse(st);

    // printing the stack
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}