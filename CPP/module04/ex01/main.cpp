#include "Cat.hpp"
#include "Dog.hpp"

int main()
{   

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    int size = 20;
    int a = -1;

    Animal* animal[size];

    std::cout << "--- Constructions---" << std::endl;
    try {
        while (++a < size/2)
            animal[a] = new Dog();
        while (a < size)
            animal[a++] = new Cat();
    } catch (const std::bad_alloc&)
    {
        for (int j = 0; j < a; j++)
            delete animal[j];
        return 1;
    }

    std::cout << "---" << std::endl;

    std::cout << "---Destructions---" << std::endl;
    for(int j = 0; j < size ; j++)
        if (animal[j])
            delete animal[j];
    return 0;
}