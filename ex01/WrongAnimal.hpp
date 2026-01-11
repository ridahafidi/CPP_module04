#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const std::string &T);
    void    setType(const std::string &T);
    const std::string &getType(void) const;
    virtual void makeSound() const;
    ~WrongAnimal();
};

#endif