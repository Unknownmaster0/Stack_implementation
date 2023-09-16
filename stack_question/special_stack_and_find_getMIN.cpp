#include <iostream>
#include <stack>
using namespace std;

/*
Question -> https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar
    given -> we need to make one special stack which will give the minimum of the stack at current situation in O(1) space and
                in O(1) time.

        example -> if the stack is  4           1st call for getMIN() -> output = 2
                                    2           now pop the first element of stack
                                    6           2nd call for getMIN() -> output = 2
                                    3           now pop the first element of stack
                                    4           3rd call for getMIN() -> output = 3
                                                now pop
                                                4th call for getMIN() -> output = 3
                                                now pop again then we left with only one element in stack i.e. 4
                                                5th call for getMIN() -> output = 4
*/

/*
Approach -> we make two stack
            1. one stack for the input
            2. another stack for - storing the min values

            input stack -> 4 2 6 3 4
            min stack ->   2 2 3 3 4  // using the above approach.
*/

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        // if come to push the first element in stack
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }

        // if already the element is present in the stack
        else if (data < mini)
        {
            int val = 2 * data - mini;
            // push the val, not data
            s.push(val);
            mini = data;
        }
        else
            s.push(data);
    }

    void pop()
    {
        // underflow condition
        if (s.empty())
            return;

        int curr = s.top();
        if (curr < mini)
        {
            int val = 2 * mini - curr;
            mini = val;
            s.pop();
        }
        else
            s.pop();
    }

    int top()
    {
        // check if the top element is less then mini or not.
        if (s.top() < mini)
        {
            return mini;
        }
        else
            return s.top();
    }

    int getMin()
    {
        if (s.empty())
            return -1;

        return mini;
    }
};

int main()
{

    return 0;
}