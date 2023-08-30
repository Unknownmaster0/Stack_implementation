#include <iostream>
#include <stack>
using namespace std;

/*
valid parenthesis -> means if the closing brackets and opening brackets are present in correct order.
                example -> [{()}] -> valid parenthesis.
                            [()] -> valid parenthesis.
                            [(]) -> Not valid parenthesis.
*/
/*
    Concept to solve ->  Time complexity -> O(n) [n is the size of the string.]
                        Space complexity -> O(n) [n is the size of the string.]
            1. if we find any closing bracket in the string, then we need to check if the top character of the stack is opening bracket of the same bracket.
                if yes, then pop out the character from the stack.
                and if no, return false. NOt valid parenthesis.
            2. if we are getting the opening brackets then push that in the stack.
            3. Check at last whether the stack is empty at last or not.
                 If yes, then valid parenthesis
                 else not.

*/
bool isMatch(char ch, stack<char> s)
{
    char top = s.top(); // top character of the stack.
    if (ch == ')' && top == '(')
        return true;
    else if (ch == ']' && top == '[')
        return true;
    else if (ch == '}' && top == '{')
        return true;

    else
        return false;
}

bool isValidParenthesis(string str)
{
    stack<char> s;

    int i = 0;
    while (i < str.length())
    {
        char ch = str[i];
        // if opening brackets then push into the stack ->
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);

        // else closing brackets hai, then check whether the top element of the stack is opening bracket of current bracket or not.
        else
        {
            // if the stack is not empty.
            if (!s.empty())
            {
                if (isMatch(ch, s))
                {
                    s.pop();
                }
                // if not correct match, then not valid parenthesis.
                else
                    return false;
            }
            // if the stack is empty and we are finding the opening bracket in it.
            else
            {
                return false;
            }
        }

        i++;
    }

    // at finally stack must be empty.
    if (s.empty())
        return true;

    return false;
}

int main()
{
    string str = "[()])";

    if (isValidParenthesis(str))
    {
        cout << "valid parenthesis." << endl;
    }
    else
    {
        cout << "Not valid parenthesis." << endl;
    }

    return 0;
}