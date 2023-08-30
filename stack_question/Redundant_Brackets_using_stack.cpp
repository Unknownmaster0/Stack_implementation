/*
    Redundant Brackets -> Any brackets of no use called Redundant Brackets.
                        Ex -> ((a+b)) -> redundant bracket.
                            (a + (b * c)) -> no redundant bracket
*/
#include <iostream>
#include <stack>
using namespace std;

/*
    Concept ->
                1. If the string character is open bracket || operator, then push back into the stack.
                2. If the string character is closing bracket || lower case alphabets then do some different things ->
                    if lower case then not do anything or simply ignore it.
                    else in case of closing braket ')'
                    check if before reaching to the '(' opening bracket any operator is come in its way or not.
                    If yes, then not redundant.
                    else redundant.
*/

bool isRedundant(string str)
{
    stack<char> s;

    int i = 0;
    while (i < str.length())
    {
        char ch = str[i];
        // 1. If the string character is open bracket || operator, then push back into the stack.
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);

        else
        {
            // else in case of closing braket ')'
            // check if before reaching to the '(' opening bracket any operator is come in its way or not.
            // If yes, then not redundant.
            // else redundant.
            if (ch == ')')
            {
                bool redundant = true;
                while (s.top() != '(')
                {
                    char str = s.top();
                    if (str == '+' || str == '-' || str == '*' || str == '/')
                    {
                        redundant = false;
                    }

                    s.pop();
                }
                s.pop(); // after coming from the loop the top element of the stack is opening bracket of the previous closing bracket, so delete it.
                if (redundant == true)
                    return true;
            }
        }
        i++;
    }

    return false;
}

int main()
{
    string str = " '(', 'a', '+', '(', 'b', '*', 'c', ')', ')' ";

    if (isRedundant(str))
    {
        cout << "the brackets are redundant." << endl;
    }
    else
    {
        cout << "Not redundant." << endl;
    }
    return 0;
}