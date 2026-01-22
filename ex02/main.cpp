#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Animal obj; // This line would not compile - Animal is abstract!

    // Test that Dog and Cat can still be instantiated
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n=== Testing polymorphism ===\n";
    j->makeSound();
    i->makeSound();

    std::cout << "\n=== Testing deep copy ===\n";
    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "\n=== Cleaning up ===\n";
    delete j;
    delete i;

    return 0;
}