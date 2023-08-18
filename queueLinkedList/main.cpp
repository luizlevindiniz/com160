#include <iostream>
#include "queue.h"

using namespace std;


int main() {


    Queue Queue;
    Queue.enqueue(10);
    Queue.enqueue(20);
    int rem = Queue.dequeue();
    cout << rem << endl; //10
    Queue.enqueue(30);
    cout << Queue.isEmpty() << " " << Queue.isFull() << endl; //0 0
    Queue.print(); //20 30
    Queue.dequeue(); //20
    Queue.dequeue(); //30
    cout << Queue.isEmpty() << " " << Queue.isFull() << endl; //1 0
    try{
        Queue.dequeue();
    } catch (exception &e) {
        cout << e.what() <<endl; //catch empty queue error
    }

    return 0;

}
