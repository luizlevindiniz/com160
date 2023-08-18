#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
private:
    /* data */
    int ra;
    std::string name;

public:
    Student();
    Student(int ra, std::string name);
    int getRa() const;
    std::string getName() const;
};

#endif // STUDENT_H