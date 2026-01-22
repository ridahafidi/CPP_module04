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

    std::cout << "\n--- WrongAnimal Test ---\n";
    const WrongAnimal *hmar = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat(); // Pointer to base class
    const WrongCat *qita = new WrongCat();

    std::cout << hmar->getType() << std::endl;
    std::cout << wrongCat->getType() << std::endl;
    std::cout << qita->getType() << std::endl;
    hmar->makeSound();    // WrongAnimal sound
    wrongCat->makeSound(); // WrongAnimal sound (not WrongCat - no polymorphism!)
    qita->makeSound();    // WrongCat sound (direct call)

    delete j;
    delete i;
    delete meta;
    delete hmar;
    delete wrongCat;
    delete qita;
    return 0;
}