#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    brain = new Brain;
    std::cout << "Cat Constructor called\n";
}

Cat::Cat(const Cat &other):Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy Constructor called\n";
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy Assignment Operator called\n";
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
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
