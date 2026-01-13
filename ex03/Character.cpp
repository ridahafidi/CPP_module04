#include "Character.hpp"

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "The index given is out of range use an index betwee 0 ~ 3\n";
        return ;
    }
    inventory[idx]->use(target);
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "The index given is out of range use an index betwee 0 ~ 3\n";
        return ;
    }
    inventory[idx]->setType("Empty Type");
}
void Character::equip(AMateria *m)
{
    int  i = 0;
    while (inventory[i]->getType().empty() == false && i <= 3)
        i++;
    if (i == 3 && inventory[i]->getType().empty() == false)
    {
        std::cout << "No more place left to equip this item\n";
        return ;
    }
    inventory[i] = m;
    std::cout << "Equipped on slot : " << i << std::endl;
    return ;

}

const std::string &Character::getName()const
{
    return (name);
}
void Character::setName(const std::string &NewName)
{
    name = NewName;
}

Character & Character::operator=(const Character & other)
{
    Character ret;
    ret.setName(other.getName());
    int i = 0;
    while(i <= 3)
    {
        ret.inventory[i] = other.inventory[i];
        i++;
    }
    return (ret);
}

Character::Character(const Character &other)
{
    setName(other.getName());
    int i = 0;
    while(i <= 3)
    {
        inventory[i] = other.inventory[i];
        i++;
    }
}

Character::Character(std::string const &N):name(N),inventory({0,0,0,0})
{
    std::cout << "Parametrized Costructor called\n";
}

Character::Character():name(""),inventory({0,0,0,0})
{
    std::cout << "Character Consructor called\n";
} 
Character::~Character()
{
    std::cout << "Character Destrcutor called\n";
}
