#include "Animal.hpp"

Animal::Animal():type("Unknown")
{
    std::cout << "Default Constructor called\n";
}

Animal::Animal(const std::string &T):type(T)
{
    std::cout << "Parametrized Constructor called\n";
}

Animal::Animal(const Animal &other):type(other.type)
{
    std::cout << "Copy Constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Copy Assignment Operator called\n";
    if (this != &other)
        type = other.type;
    return (*this);
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
