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
    // Note: Subject says unequip must NOT delete the Materia
    // The caller is responsible for handling/deleting the unequipped materia
    inventory[idx] = 0;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
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
    std::cout << "Character Copy Assignment Operator called\n";
    if (this != &other)
    {
        name = other.name;
        // Delete existing inventory
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
        }
        // Deep copy inventory
        for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return (*this);
}

Character::Character(const Character &other):name(other.name)
{
    std::cout << "Character Copy Constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
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
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
    std::cout << "Character Destrcutor called\n";
}
