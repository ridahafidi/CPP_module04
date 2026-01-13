#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string Type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria &operator=(const AMateria &other);
    ~AMateria();
    std::string const & getType() const;
    void    setType(const std::string &NewType);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

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
void AMateria::use(ICharacter& target)
{
    if (Type == "ice")
        std::cout << "Shoots an ice bolt at " << target.getName() << '\n';
    else if (Type == "cure")
        std::cout << "heals " << target.getName() << "’s wound\n";
    else
        std::cout << "I m of type : " << target.getName() << " Use a Cure or Ice Materia type instead\n";
}
AMateria::~AMateria()
{
    std::cout << "Destructor called\n";
}

void    AMateria::setType(const std::string &NewType)
{
    Type = NewType;
}

#endif