#include "Brain.hpp"

Brain::Brain(const Brain &other)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = other.ideas[i];
        i++;
    }
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        int i = 0;
        while (i < 100)
        {
            this->ideas[i] = other.ideas[i];
            i++;
        }
    }
    return (*this);
}

Brain::Brain()
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = "I think";
        i++;
    }
    std::cout << "Brain Constructor called\n";
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called\n";
}

Brain::Brain(const std::string &IdeaOwner)
{
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = "I think " + IdeaOwner;
        i++;
    }
    std::cout << "Brain Constructor called\n";
}
