#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Animal
{
    protected:
        std::string type;
        Animal(const std::string& type);

    public:
        Animal();
        Animal(const Animal& copyObject);

        virtual ~Animal();

        std::string getType() const;

        virtual void makeSound() const = 0;

        Animal& operator=(const Animal& copyObject);
};

#endif