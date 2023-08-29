// question -> https://www.codingninjas.com/studio/problems/two-stacks_983634?leftPanelTab=1&campaign=YouTube_CodestudioLovebabbar5thfeb

#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
/*
We just use the array size in more judicious way here.

Initialising the top1 -> from the left side of the array.
Initialising the top2 -> from the right side of the array.

we need four data members :
        1. top1, 2. top2, 3. array, 4. size -> for the size of the array.
*/
class TwoStack {
    int *arr;
    int top1, top2, size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // these are things that we do when any stack is created.
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // we push the element if there is any space in the stack.
        if(top2 - top1 > 1) // means atleast one space hai.
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // we push the element if there is any space in the stack.
        if(top2 - top1 > 1) // means atleast one space hai.
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // we can pop only when stack is not empty.
        if(top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};




int main()
{
    
    return 0;
}