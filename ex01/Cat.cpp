#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    std::cout << "Cat Constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called\n";
}

void Cat::makeSound()const
{
    std::cout << "Meoww\n";
}
