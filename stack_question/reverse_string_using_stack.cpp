#include<iostream>
#include<stack>
using namespace std;

// This is characteristics of the stack -> You get the element in the reverse order from the stack.

int main()
{
    string input = "sagar";

// initialising the stack -> 
    stack<char>s;

// pushing all the elements of the string in stack.
    int i = 0;
    while(i < input.size())
    {
        char ch = input[i];
        s.push(ch);
        i++;
    }

    string ans = ""; // string to store the ans.
// getting the value from the stack.
    while(!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout<<"answer -> "<<ans<<endl;

    return 0;
}