#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue() {

    head = NULL;
    tail = NULL;

}

Queue::~Queue() {

    struct Node *delPointer;
    delPointer = head;

    while(delPointer != NULL) {
        head = head->next;
        delete delPointer;
        delPointer = head;

    }

    tail = NULL;

}


void Queue::print() const {

    struct Node *auxPointer;
    auxPointer = head;

    while (auxPointer != NULL) {

        cout << auxPointer->value << " ";
        auxPointer = auxPointer->next;
    }

    cout << endl;
    delete auxPointer;

}

bool Queue::isEmpty() const {

    return (head == NULL);
}

bool Queue::isFull() const {

    struct Node *isPossible;

    try {

        isPossible = new struct Node;
        delete isPossible;

        return false;

    } catch (bad_alloc &exception) {

        return true;

    }
}


void Queue::enqueue(ItemType item) {

    if (!isFull()) {

        struct Node *newNode = new struct Node;
        newNode->value = item;
        newNode->next = NULL;

        if (!isEmpty()) {

            tail->next = newNode;

        } else {

            head = newNode;

        }

        tail = newNode;


    } else {

        throw runtime_error ("Overflow! Queue is Full!");
    }

}

ItemType Queue::dequeue() {

    if(!isEmpty()) {

        struct Node *delPointer;
        delPointer = head;
        ItemType removedItem = delPointer->value;
        head = head->next;
        delete delPointer;

        if (head == NULL) {

            tail = NULL;
        }

        return removedItem;

    } else {

        throw runtime_error ("Underflow! Queue is Empty!");
    }

}
