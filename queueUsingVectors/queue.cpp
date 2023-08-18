#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()
{

    structure = new ItemType[MAX];
    f = -1;
    r = -1;
}

Queue::~Queue()
{

    delete[] structure;
}

bool Queue::isEmpty() const
{

    if (f == r)
    {

        cout << f << " " << r << endl;
        return true;
    }

    return false;
}

bool Queue::isFull() const
{

    if (f - 1 == r)
    {
        return true;
    }

    return false;
}

void Queue::print() const
{

    for (int i = f; i != r; i = (i + 1) % MAX)
    {
        cout << structure[i];
    }
    cout << endl;
}

void Queue::enqueue(ItemType item)
{

    if (!isFull())
    {
        if (f == -1)
        {
            f = 0;
            r = 0;
        }
        if (r % MAX == 0)
        {
            r = 0;
        }
        structure[r] = item;
        r = r + 1;
    }
    else
    {
        throw runtime_error("Overflow! Queue is Full!");
    }
}

ItemType Queue::dequeue()
{

    if (!isEmpty())
    {
        if (f % MAX == 0)
        {
            f = 0;
        }
        ItemType rem = f;
        f = f + 1;
        return rem;
    }
    else
    {
        throw runtime_error("Underflow! Queue is Empty!");
        }
}
