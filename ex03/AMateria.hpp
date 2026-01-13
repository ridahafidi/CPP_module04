#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

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


#endif