#include <iostream>
#include "student.h"

Student::Student()
{
    this->ra = -1;
    this->name = "";
}

Student::Student(int ra, std::string name)
{
    this->ra = ra;
    this->name = name;
}

int Student::getRa() const
{
    return this->ra;
}

std::string Student::getName() const
{
    return this->name;
}
