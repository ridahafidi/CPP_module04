#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    brain = new Brain;
    std::cout << "Dog Constructor called\n";
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
