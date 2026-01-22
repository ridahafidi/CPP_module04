#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice():AMateria("ice")
{
    std::cout << "Ice Constructor called\n";
}

Ice::Ice(const Ice &other):AMateria(other)
{
    std::cout << "Ice Copy Constructor called\n";
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice Copy Assignment Operator called\n";
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called\n";
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}