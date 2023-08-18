#include <iostream>
#include "queue.h"

using namespace std;


int main(){

    Queue fila;
    fila.enqueue(1);
    fila.enqueue(2);
    fila.print();
    fila.dequeue();
    fila.enqueue(3);
    fila.print();

return 0;

}
