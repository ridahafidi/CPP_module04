#ifndef I_MATERIA_SOURCE_HPP
#define I_MATERIA_SOURCE_HPP

#include"AMateria.hpp"

class IMateriaSource
{
public:
virtual ~IMateriaSource() {std::cout << "IMateria Destructor called\n";}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif