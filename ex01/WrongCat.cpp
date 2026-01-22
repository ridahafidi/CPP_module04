#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy Assignment Operator called\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}

void WrongCat::makeSound()const
{
    std::cout << "WrongCat : ewa hana ntaqt\n";
}
