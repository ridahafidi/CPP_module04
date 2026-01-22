#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure Constructor called\n";
}

Cure::Cure(const Cure &other):AMateria(other)
{
    std::cout << "Cure Copy Constructor called\n";
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Copy Assignment Operator called\n";
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called\n";
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}