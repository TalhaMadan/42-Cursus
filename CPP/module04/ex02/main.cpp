#include "Cat.hpp"
#include "Dog.hpp"

int main()
{   
    int size = 20;
    int i = -1;

    Animal* animal[size];

    std::cout << "--- Constructions---" << std::endl;
    try {
        while (++i < size/2)
            animal[i] = new Dog();
        while (i < size)
            animal[i++] = new Cat();
    } catch (const std::bad_alloc&)
    {
        for (int j = 0; j < i; j++)
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
