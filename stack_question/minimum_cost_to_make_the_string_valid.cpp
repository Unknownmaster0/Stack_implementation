#include<iostream>
#include<stack>
using namespace std;

int minCostForValid(string str)
{
    // step 1 -> if the length of string is odd return -1. Not able to make it valid.
    if(str.length() % 2 != 0)
        return -1;

    stack<char>s;
    // step 2 -> remove the valid part from the string.
    int i = 0;
    while( i < str.length() )
    {
        // if opening bracket then push into stack simply.
        if(str[i] == '{')
            s.push(str[i]);
// Closing bracket then -> check if the top of stack is opening bracket or not. 
// if yes, then it is valid string, then pop the opening bracket from the stack.
// else, then not valid string then push into the stack to make it valid.
        else
        {
            if(!s.empty() && s.top() == '{')
                s.pop();

            else
                s.push(str[i]);

        }

        ++i;
    }

// after coming from the loop you have get the invalid string in the stack.
    int opening = 0, closing = 0;
    while(!s.empty())
    {
        if(s.top() == '}')
            closing++;
        else
            opening++;

        s.pop();
    }

    return (opening+1)/2 + (closing+1)/2;

}

int main()
{

    string str = "{{}}}}";
    int ans = minCostForValid(str);
    cout<<"the minimum cost is -> "<<ans<<endl;

    return 0;
}