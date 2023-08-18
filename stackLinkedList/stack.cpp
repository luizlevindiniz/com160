#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{

    top = NULL;
}

Stack::~Stack()
{

    struct Node *delPointer = top;

    while (delPointer != NULL)
    {

        top = top->next;
        delete delPointer;
        delPointer = top;
    }
}

bool Stack::isEmpty() const
{

    return (top == NULL);
}

bool Stack::isFull() const
{

    struct Node *isPossible;

    try
    {

        isPossible = new Node;
        delete isPossible;

        return false;
    }
    catch (bad_alloc &exception)
    {

        return true;
    }
}

void Stack::print() const
{

    struct Node *auxPointer = top;

    while (auxPointer != NULL)
    {

        cout << auxPointer->value;
        auxPointer = auxPointer->next;
    }

    cout << endl;
    delete auxPointer;
}

void Stack::push(ItemType item)
{

    if (!isFull())
    {

        struct Node *newNode = new struct Node;
        newNode->value = item;
        newNode->next = top;
        top = newNode;
    }
    else
    {

        throw runtime_error("Overflow! Stack is Full!");
    }
}

ItemType Stack::pop()
{

    if (!isEmpty())
    {

        struct Node *delPointer = top;
        ItemType removedItem = delPointer->value;
        top = top->next;
        delete delPointer;

        return removedItem;
    }
    else
    {

        throw runtime_error("Underflow! Stack is Empty!");
    }
}
