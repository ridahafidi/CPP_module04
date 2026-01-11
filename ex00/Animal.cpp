#include "Animal.hpp"

Animal::Animal():type("Unknown")
{
    std::cout << "Default Constructor called\n";
}

Animal::Animal(const std::string &T):type(T)
{
    std::cout << "Parametrized Constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Destructor called\n";
}

void    Animal::setType(const std::string &T)
{
    type = T;
}
const std::string &Animal::getType(void)const
{
    return (type);
}

void Animal::makeSound()const
{
    std::cout << "wach andir lrbk ana\n";
}