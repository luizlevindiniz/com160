#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "student.h"

class HashTable
{
private:
    int maxItems;
    int currentLength;
    Student *table;
    int hashFunction(Student student);

public:
    HashTable(int maxItems = 100);
    ~HashTable();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;
    int getLength() const;

    void fetchItem(Student &student, bool &wasFound);
    void insertItem(Student student);
    void deleteItem(Student student);
};

#endif // HASHTABLE_H