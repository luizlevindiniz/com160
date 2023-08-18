#ifndef STACK_H
#define STACK_H

const int MAX=100;

class Stack {

private:

    int length;
    int *structure;

public:

    Stack();
    ~Stack();
    bool isFull() const;
    bool isEmpty() const;
    void print() const;

    void push(int item);
    int pop();

};

#endif // STACK_H
