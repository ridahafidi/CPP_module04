#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    // Test with array of animals as per subject
    const int arraySize = 10;
    Animal* animals[arraySize];

    std::cout << "=== Creating array of animals ===\n";
    for (int i = 0; i < arraySize / 2; i++)
        animals[i] = new Dog();
    for (int i = arraySize / 2; i < arraySize; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Testing deep copy ===\n";
    Dog basic;
    {
        Dog tmp = basic; // Test copy constructor
    } // tmp is destroyed here, basic should still be valid

    std::cout << "\n=== Deleting animals ===\n";
    for (int i = 0; i < arraySize; i++)
        delete animals[i];

    return 0;
}