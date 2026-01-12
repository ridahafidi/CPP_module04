#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    brain = new Brain;
    std::cout << "Cat Constructor called\n";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}

void Cat::makeSound()const
{
    std::cout << "Meoww\n";
}
