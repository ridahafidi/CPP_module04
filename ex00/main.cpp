#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal *hmar = new WrongAnimal();
    const WrongCat *qita = new WrongCat();

    std::cout << hmar->getType() << std::endl;

    std::cout << qita->getType() << std::endl;
    hmar->makeSound();
    qita->makeSound();
    delete j;
    delete i;
    delete meta;
    return 0;
}