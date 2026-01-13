#include "Character.hpp"

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "The index given is out of range use an index betwee 0 ~ 3\n";
        return ;
    }
    if (inventory[idx] == 0)
    {
        std::cout << "No materia equipped in slot " << idx << "\n";
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
    if (inventory[idx] == 0)
    {
        std::cout << "No materia equipped in slot " << idx << "\n";
        return ;
    }
    inventory[idx] = 0;
}
void Character::equip(AMateria *m)
{
    int  i = 0;
    while (i < 4 && inventory[i] != 0)
        i++;
    if (i >= 4)
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
    Character *ret = new Character;
    ret->setName(other.getName());
    int i = 0;
    while(i <= 3)
    {
        ret->inventory[i] = other.inventory[i];
        i++;
    }
    return (*ret);
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

Character::Character(std::string const &N):name(N)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
    std::cout << "Parametrized Costructor called\n";
}

Character::Character():name("")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
    std::cout << "Character Consructor called\n";
} 
Character::~Character()
{
    std::cout << "Character Destrcutor called\n";
}
