#include <iostream>
#include "hash.h"
#include "string.h"

int main()
{

    std::string names[6] = {"Abran", "Bianca", "Carl", "David", "Elias", "Collision"};
    int ras[6] = {100, 101, 102, 103, 104, 105};
    HashTable hash(10);
    Student *aux = new Student[10];

    for (int i = 0; i < 6; i++)
    {
        aux[i] = Student(ras[i], names[i]);
        hash.insertItem(aux[i]);
    }

    hash.print();
    std::cout << "*------*" << std::endl;
    hash.deleteItem(aux[0]);
    hash.print();
    std::cout << "*------*" << std::endl;
    hash.insertItem(Student(110, "Replicant"));
    hash.insertItem(Student(215, "Collision course!"));
    bool wasFound = false;
    Student foo(103, "Foo");
    hash.fetchItem(foo, wasFound);
    std::cout << foo.getName() << std::endl;
    std::cout << "*------*" << std::endl;
    hash.print();
    std::cout << "*------*" << std::endl;
    Student teste(104, "AAA");
    bool found = false;
    hash.fetchItem(teste, found);
    std::cout << teste.getName() << " -> " << found << std::endl;
    std::cout << "*------*" << std::endl;
    hash.deleteItem(teste);
    hash.print();
    std::cout << "*------*" << std::endl;
    Student testa(215, "AAA");
    hash.fetchItem(testa, found);
    std::cout << testa.getName() << " -> " << found << std::endl;
    std::cout << "Fim" << std::endl;
    delete aux;

    return 0;
}