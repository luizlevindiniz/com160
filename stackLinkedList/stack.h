#ifndef STACK_H
#define STACK_H

typedef int ItemType;

struct Node {

    ItemType value;
    struct Node *next;

};


class Stack {

    private:

        struct Node *top;

    public:

        Stack();
        ~Stack();
        void print() const;
        void push(ItemType item);
        ItemType pop();
        bool isFull() const;
        bool isEmpty() const;

};


#endif // STACK_H
