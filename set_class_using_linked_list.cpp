#include <iostream>
#include <vector>
using namespace std;

/*
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class MyHashSet
{
    Node *head;

public:
    MyHashSet()
    {
        head = NULL;
    }

    void add(int key)
    {
        Node *newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    void remove(int key)
    {
        if (head == NULL)
            return; // no data to remove

        // if the head element is the key to remove
        if (head->data == key)
        {
            head = head->next;
            return;
        }
        // else
        Node *temp = head;
        while (temp->next != NULL && temp->next->data != key)
            temp = temp->next;

        if (temp->next != NULL)
        {
            temp->next = temp->next->next;
            return;
        }
    }

    bool contains(int key)
    {
        Node *temp = head;
        if (temp == NULL)
            return false;

        while (temp != NULL)
        {
            if (temp->data == key)
                return true;

            temp = temp -> next;
        }

        return false;
    }
};
*/

// nice way of doing the above thing in different manner
class MyHashSet
{
    // this vector indexes are the key of the set and the value in the vector indexes is true or false, helps us to remove or check if the vector contains the key or not.
    vector<bool> v;

public:
    MyHashSet()
    {
        v.resize(1000001, false);
    }

    void add(int key)
    {
        v[key] = true;
    }

    void remove(int key)
    {
        // to remove the element vector must contains that element.
        if (v[key] == true) // means the vector contains the element.
            v[key] = false;
    }

    bool contains(int key)
    {
        // as the vector element is the bool, so at index = key, whatever the bool is, simply return that only.
        // if false then the vector doesn't contains that.
        // if true means the vector contains that.
        return v[key];
    }
};

int main()
{

    MyHashSet *set = new MyHashSet();
    set->add(6);
    set->add(7);
    set->add(5);

    if (set->contains(4))
        cout << "Yes, Present." << endl;
    else
        cout << "Absent." << endl;

    set->remove(5);
    if (set->contains(5))
        cout << "yes, present." << endl;
    else
        cout << "Absent." << endl;

    cout << "6 is present or not -> " << set->contains(6) << endl;
    set->remove(6);
    cout << "6 is present or not -> " << set->contains(6) << endl;

    return 0;
}