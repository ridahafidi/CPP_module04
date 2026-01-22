#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type):Type(type)
{
    std::cout << "Parametrized Constructor called\n";
}
std::string const & AMateria::getType() const
{
    return (Type);
}

AMateria::AMateria():Type("Empty Type")
{
    std::cout << "Default Constructor called\n";
}

AMateria::AMateria(const AMateria &other):Type(other.Type)
{
    std::cout << "AMateria Copy Constructor called\n";
}

void AMateria::use(ICharacter& target)
{
    if (Type == "ice")
        std::cout << "Shoots an ice bolt at " << target.getName() << '\n';
    else if (Type == "cure")
        std::cout << "heals " << target.getName() << "’s wound\n";
    else
        std::cout << "I have no type yet to be used!\n";
}
AMateria::~AMateria()
{
    std::cout << "Destructor called\n";
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        Type = other.Type;
    return (*this);
}

void    AMateria::setType(const std::string &NewType)
{
    Type = NewType;
}
