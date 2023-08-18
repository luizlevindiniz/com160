#ifndef QUEUE_H
#define QUEUE_H
typedef int ItemType;

const int MAX=100;

class  Queue{

private:

    ItemType *structure;
    ItemType f;
    ItemType r;

public:

    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;
    void enqueue(ItemType item);
    ItemType dequeue();

};

#endif // QUEUE_H
