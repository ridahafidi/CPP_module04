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
    if (droppedCount >= droppedCapacity)
    {
        int newCapacity;
        if (droppedCapacity == 0)
        newCapacity = 4;
        else
        newCapacity = droppedCapacity * 2;
        AMateria** newArray = new AMateria*[newCapacity];
        int i = 0;
        while (i < droppedCount)
        {
            newArray[i] = droppedMaterias[i];
            i++;
        }
        while (i < newCapacity)
        {
            newArray[i] = 0;
            i++;
        }
        if (droppedMaterias)
            delete[] droppedMaterias;
        droppedMaterias = newArray;
        droppedCapacity = newCapacity;
    }
    droppedMaterias[droppedCount] = inventory[idx];
    droppedCount++;
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
        delete m;
        return ;
    }
    int j  = 0;
    while (j < droppedCount)
    {
        if (droppedMaterias[j] == m)
        {
            droppedMaterias[j] = 0;
            break;
        }
        j++;
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
        int i = 0;
        name = other.name;
        while(i < 4)
        {
            if (inventory[i])
                delete inventory[i];
            i++;
        }
        i = 0;
        while (i < 4)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
            i++;
        }
        i = 0;
        while (i < droppedCount)
        {
            delete droppedMaterias[i];
            i++;
        }
        if (droppedMaterias)
            delete[] droppedMaterias;
        droppedCount = other.droppedCount;
        droppedCapacity = other.droppedCapacity;
        if (droppedCapacity > 0)
        {
            droppedMaterias = new AMateria*[droppedCapacity];
            i = 0;
            while (i < droppedCount)
            {
                droppedMaterias[i] = other.droppedMaterias[i]->clone();
                i++;
            }
            while (i < droppedCapacity)
            {
                droppedMaterias[i] = 0;
                i++;
            }
        }
        else
            droppedMaterias = 0;
    }
    return (*this);
}

Character::Character(const Character &other):name(other.name), droppedCount(other.droppedCount), droppedCapacity(other.droppedCapacity)
{
    std::cout << "Character Copy Constructor called\n";
    int i = 0;
    while (i < 4)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
        i++;
    }
    if (droppedCapacity > 0)
    {
        droppedMaterias = new AMateria*[droppedCapacity];
        i = 0;
        while (i < droppedCount)
        {
            droppedMaterias[i] = other.droppedMaterias[i]->clone();
            i++;
        }
        while (i < droppedCapacity)
        {
            droppedMaterias[i] = 0;
            i++;
        }
    }
    else
        droppedMaterias = 0;
}

Character::Character(std::string const &N):name(N), droppedMaterias(0), droppedCount(0), droppedCapacity(0)
{
    int i = 0;
    while(i < 4)
    {
        inventory[i] = 0;
        i++;
    }
    std::cout << "Parametrized Costructor called\n";
}

Character::Character():name(""), droppedMaterias(0), droppedCount(0), droppedCapacity(0)
{
    int i = 0;
    while (i < 4)
    {
        inventory[i] = 0;
        i++;
    }
    std::cout << "Character Consructor called\n";
}

Character::~Character()
{
    int i = 0;
    while (i < 4)
    {
        if (inventory[i])
            delete inventory[i];
        i++;
    }
    i = 0;
    while (i < droppedCount)
    {
        delete droppedMaterias[i];
        i++;
    }
    if (droppedMaterias)
        delete[] droppedMaterias;
    std::cout << "Character Destrcutor called\n";
}
