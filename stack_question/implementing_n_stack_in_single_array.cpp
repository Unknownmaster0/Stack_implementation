#include <iostream>
using namespace std;

/*
    You have given, n number of stacks and one single array. You need to make the user defined function of push and pop
    for all stacks using the single array.
*/

class Nstack
{
    int *arr;
    int *top;
    int *next;
    int stackNumber, arraySize;
    int freeSpace;

public:
    // here x -> the number that is to pushed.
    // m -> in which stack number you need to push.
    bool push(int x, int m)
    {
        // condition of pushing the elements in stack
        if (freeSpace == -1) // no freeSpace to push.
            return false;

        // steps of pushing the index

        // step 1 -> finding the index where to push element
        int index = freeSpace;

        // step 2 -> push the element in arr of stack
        arr[index] = x;

        // step 3 -> updating the freespace
        freeSpace = next[index];

        // step 4 -> updating the next
        next[index] = top[m - 1];

        // step 5 -> updating the top
        top[m - 1] = index;

        return true;
    }

    // and just uska ulta kr dene pr pop() function ready hoo jayega.

    int pop(int m)
    {
        // condition for the pop() -> if the stack is empty before
        if (top[m - 1] == -1)
            return -1;

        // just reverse of push

        // step 1 -> finding the index to pop
        int index = top[m - 1]; // index to pop is the top index.

        // step 2 -> update the top
        top[m - 1] = next[index];

        // step 3 -> update the next
        next[index] = freeSpace;

        // step 4 -> updating the freespace
        freeSpace = index;

        return arr[index];
    }
};

int main()
{

    return 0;
}