#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    int arraySize = 10;
    
    Animal* animals[arraySize];
    std::cout << "=== Creating array of animals ===\n";
    
    int i = 0;
    while(i < arraySize / 2)
    {
        animals[i] = new Dog();
            i++;
    }
    i = arraySize / 2;
    while (i < arraySize)
    {
        animals[i] = new Cat();
        i++;
    }
    
    std::cout << "\n=== Testing deep copy ===\n";
    
    Dog basic;
    Dog tmp = basic;
    
    std::cout << "\n=== Deleting animals ===\n";
    
    i = 0;
    while (i < arraySize)
    {
        delete animals[i];
        i++;
    }

    return 0;
}