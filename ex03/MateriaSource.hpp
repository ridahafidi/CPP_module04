#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource
{
    protected:
        AMateria *storage;
    public:
    MateriaSource();
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource():storage(0)
{
    std::cout << "MateriaSource Constructor called\n";
}

MateriaSource::~MateriaSource()
{
    std::cout <<  "MateriaSource Destructor called\n";
}
void MateriaSource::learnMateria(AMateria *m)
{
    *storage = *m;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "ice")
    {
        AMateria *ret  = new Ice;
        *ret = *storage;
        return (ret);
    }
    else if (type == "cure")
    {
        AMateria *ret  = new Cure;
        *ret = *storage;
        return (ret);
    }
    else
        return (0);
}


#endif