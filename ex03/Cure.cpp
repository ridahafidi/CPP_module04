#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure Constructor called\n";
}

Cure::~Cure()
{
    std::cout << "Cure Destructor calld\n";
}
AMateria* Cure::clone() const
{
    AMateria *ret = new Cure;
    return (ret);
}