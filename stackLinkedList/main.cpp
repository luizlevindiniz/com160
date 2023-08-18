#include <iostream>
#include "stack.h"

using namespace std;

int main()
{

    Stack Stack;
    Stack.push(10);
    Stack.push(20);
    int rem = Stack.pop();
    cout << rem << endl; // 20
    Stack.push(30);
    cout << Stack.isEmpty() << " " << Stack.isFull() << endl; // 0 0
    Stack.print();                                            // 30 10
    Stack.pop();                                              // 30
    Stack.pop();                                              // 10
    cout << Stack.isEmpty() << " " << Stack.isFull() << endl; // 1 0
    try
    {
        Stack.pop();
    }
    catch (exception &e)
    {
        cout << e.what() << endl; // catch empty stack error
    }

    return 0;
}
