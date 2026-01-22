#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while(i < 4)
    {
        storage[i] = 0;
        i++;
    }
    std::cout << "MateriaSource Constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy Constructor called\n";
    int i = 0;
    while(i < 4)
    {
        if (other.storage[i])
            storage[i] = other.storage[i]->clone();
        else
            storage[i] = 0;
        i++;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy Assignment Operator called\n";
    if (this != &other)
    {
        int i = 0;
        while (i < 4)
        {
            if (storage[i])
                delete storage[i];
            if (other.storage[i])
                storage[i] = other.storage[i]->clone();
            else
                storage[i] = 0;
            i++;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    int i = 0;

    while (i < 4)
    {
        if (storage[i])
            delete storage[i];
        i++;
    }
    std::cout << "MateriaSource Destructor called\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;
    while (i < 4)
    {
        if (storage[i] == 0)
        {
            storage[i] = m;
            return;
        }
        i++;
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 3;
    while (i >= 0)
    {
        if (storage[i] && storage[i]->getType() == type)
            return storage[i]->clone();
        i--;
    }
    return (0);
}
