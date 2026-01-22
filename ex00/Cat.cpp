#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    std::cout << "Cat Constructor called\n";
}

Cat::Cat(const Cat &other):Animal(other)
{
    std::cout << "Cat Copy Constructor called\n";
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy Assignment Operator called\n";
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called\n";
}

void Cat::makeSound()const
{
    std::cout << "Meoww\n";
}
