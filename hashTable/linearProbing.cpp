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
    int startLocation = hashFunction(student);
    int location = startLocation;
    wasFound = table[location].getRa() == student.getRa();

    do
    {
        wasFound = table[location].getRa() == student.getRa();
        if (!wasFound)
        {
            location = (location + 1) % maxItems;
        }
    } while (!wasFound && startLocation != location);

    if (wasFound)
    {

        student = table[location];
    }
    else
    {
        std::cout << "Student not found!" << std::endl;
    }
}

void HashTable::insertItem(Student student)
{
    if (!isFull())
    {
        int startLocation = hashFunction(student);
        int location = startLocation;

        do
        {
            if (table[location].getRa() < 0)
            {
                table[location] = student;
                currentLength += 1;
            }
            else
            {
                location = (location + 1) % maxItems;
            }
        } while (table[location].getRa() < 0 && startLocation != location);
    }
    else
    {
        std::cout << "Is Full!" << std ::endl;
    }
}

void HashTable::deleteItem(Student student)
{
    if (!isEmpty())
    {

        int startLocation = hashFunction(student);
        int location = startLocation;
        bool wasFound = table[location].getRa() == student.getRa();

        do
        {
            if (wasFound)
            {
                table[location] = Student(-2, "<deleted>");
                currentLength -= 1;
            }
            else
            {
                location = (location + 1) % maxItems;
            }
        } while (!wasFound && startLocation != location);

        if (!wasFound)
        {

            std::cout << "Student not found!" << std::endl;
        }
    }
    else
    {
        std::cout << "Is Empty!" << std::endl;
    }
}