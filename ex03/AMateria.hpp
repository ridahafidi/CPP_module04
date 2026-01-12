#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
    std::string Name;
    std::string Type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria &operator=(const AMateria &other);
    ~AMateria();
    std::string const & getName() const;
    void setName(const std::string &NewName);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    std::string const & getType() const;
    void    setType(const std::string &NewType);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

void AMateria::setName(const std::string &NewName)
{
    Name = NewName;
}
AMateria::AMateria(std::string const & type):Type(type),Name("")
{
    std::cout << "Parametrized Constructor called\n";
}
std::string const & AMateria::getType() const
{
    return (Type);
}

AMateria::AMateria():Type(""),Name("")
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

std::string const & AMateria::getName() const
{
    return (Name);
}

void    AMateria::setType(const std::string &NewType)
{
    Type = NewType;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    setName(other.getName());
}

void AMateria::equip(AMateria* m)
{
    int index = 0;

    while (index <= 3)
    {
        if ((this + index)->getType().empty() == true)
        {
            this[index] = *m;
        }
        index++;
    }
    
}
void AMateria::unequip(int idx)
{
    
}
void AMateria::use(int idx, ICharacter& target)
{
    
}

#endif