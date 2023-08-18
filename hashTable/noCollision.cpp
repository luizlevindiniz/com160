#include <iostream>
#include "hash.h"

HashTable::HashTable(int max)
{
    this->maxItems = max;
    this->currentLength = 0;
    this->table = new Student[maxItems];
}

HashTable::~HashTable()
{
    delete[] table;
}

bool HashTable::isEmpty() const
{
    return currentLength == 0;
}

bool HashTable::isFull() const
{
    return currentLength == maxItems;
}
void HashTable::print() const
{
    for (int i = 0; i < maxItems; i++)
    {
        std::cout << table[i].getRa() << "-" << table[i].getName() << std::endl;
    }
}
int HashTable::getLength() const
{
    return currentLength;
}
int HashTable::hashFunction(Student student)
{
    return student.getRa() % maxItems;
}
void HashTable::fetchItem(Student &student, bool &wasFound)
{
    int location = hashFunction(student);
    Student aux = table[location];

    if (aux.getRa() != student.getRa())
    {
        wasFound = false;
    }
    else
    {
        wasFound = true;
        student = aux;
    }
}
void HashTable::insertItem(Student student)
{
    int location = hashFunction(student);
    table[location] = student;
    currentLength += 1;
}
void HashTable::deleteItem(Student student)
{
    int location = hashFunction(student);
    table[location] = Student();
    currentLength -= 1;
}