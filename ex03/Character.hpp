#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria*   inventory[4];
public:
    Character();
    Character(std::string const & N);
    Character(const Character & other);
    Character & operator=(const Character & other);
    virtual ~Character();
    std::string const & getName() const;
    void    setName(const std::string &NewName);
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif