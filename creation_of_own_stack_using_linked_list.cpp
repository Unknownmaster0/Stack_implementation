#include<iostream>
#include "Stack_class_using_linked_list.cpp"
using namespace std;

int main()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    cout<<"size of stack -> "<<s.total_size()<<endl;
    while( ! s.empty() ){
        cout<<"the data in the stack is -> " <<s.top_data()<<endl;
        s.pop();
    }
    cout<<"size of stack -> "<<s.total_size()<<endl;


    // s.pop();

    if(s.empty())
    {
        cout<<"stack is empty."<<endl;
    }
    else
    {
        cout<<"stack is not empty."<<endl;
    }


    return 0;
}