#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout << "Dog Constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called\n";
}
void Dog::makeSound()const
{
    std::cout << "BARK! BARK!\n";
}
