#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
    std::cout << "Ice Constructor called\n";
}

Ice::~Ice()
{
    std::cout << "Ice Deconstructor called\n";
}

AMateria* Ice::clone() const
{
    AMateria *ret = new Ice;
    return (ret);
}