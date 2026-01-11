#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Unknown")
{
    std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string &T):type(T)
{
    std::cout << "WrongAnimal Parametrized Constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called\n";
}

void    WrongAnimal::setType(const std::string &T)
{
    type = T;
}
const std::string &WrongAnimal::getType(void)const
{
    return (type);
}

void WrongAnimal::makeSound()const
{
    std::cout << "WrongAnimal : wach andir lrbk ana\n";
}