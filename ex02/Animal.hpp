#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const std::string &T);
    void    setType(const std::string &T);
    const std::string &getType(void) const;
    virtual void makeSound() const = 0;
    virtual ~Animal();
};

#endif