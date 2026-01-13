#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria *storage[4];
    public:
    MateriaSource();
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        storage[i] = 0;
    std::cout << "MateriaSource Constructor called\n";
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (storage[i])
            delete storage[i];
    }
    std::cout <<  "MateriaSource Destructor called\n";
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


#endif