#ifndef QUEUE_H
#define QUEUE_H

typedef int ItemType;

struct Node
{

    ItemType value;
    struct Node *next;
};

class Queue
{

private:
    struct Node *head;
    struct Node *tail;

public:
    Queue();
    ~Queue();

    void print() const;
    void enqueue(ItemType item);
    ItemType dequeue();
    bool isEmpty() const;
    bool isFull() const;
};

#endif // QUEUE_H
