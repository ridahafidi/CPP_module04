#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        storage[i] = 0;
    std::cout << "MateriaSource Constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy Constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (other.storage[i])
            storage[i] = other.storage[i]->clone();
        else
            storage[i] = 0;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy Assignment Operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (storage[i])
                delete storage[i];
            if (other.storage[i])
                storage[i] = other.storage[i]->clone();
            else
                storage[i] = 0;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (storage[i])
            delete storage[i];
    }
    std::cout << "MateriaSource Destructor called\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (storage[i] == 0)
        {
            storage[i] = m;
            return;
        }
    }
    // If no space, delete the materia to avoid memory leak
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; i--)
    {
        if (storage[i] && storage[i]->getType() == type)
            return storage[i]->clone();
    }
    return (0);
}
