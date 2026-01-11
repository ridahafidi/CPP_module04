#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}

void WrongCat::makeSound()const
{
    std::cout << "WrongCat : ewa hana ntaqt\n";
}
