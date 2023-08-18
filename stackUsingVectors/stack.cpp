#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{

    length = 0;
    structure = new int[MAX];
}

Stack::~Stack()
{

    delete[] structure;
}

bool Stack::isEmpty() const
{

    if (this->length == 0)
    {
        return true;
    }

    return false;
}

bool Stack::isFull() const
{

    if (this->length == MAX)
    {
        return true;
    }

    return false;
}

void Stack::print() const
{
    for (int i = 0; i < this->length; i++)
    {
        cout << structure[i];
    }
    cout << endl;
}

int Stack::pop()
{
    if (!isEmpty())
    {

        int r = structure[length - 1];
        length -= 1;
        return r;
    }
    else
    {

        throw runtime_error("Underflow! Stack is Empty!");
        ;
    }
}

void Stack::push(int item)
{
    if (!isFull())
    {

        structure[length] = item;
        length += 1;
    }

    else
    {
        throw runtime_error("Overflow! Stack is Full!");
    }
}
