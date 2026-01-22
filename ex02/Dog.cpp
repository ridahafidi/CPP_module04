#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    brain = new Brain;
    std::cout << "Dog Constructor called\n";
}

Dog::Dog(const Dog &other):Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy Constructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy Assignment Operator called\n";
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}

void Dog::makeSound()const
{
    std::cout << "BARK! BARK!\n";
}
