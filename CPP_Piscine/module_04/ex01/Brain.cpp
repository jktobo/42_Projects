#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy constructor Brain called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copy assignment operator Brain called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Destructor Brain called" << std::endl;
}

std::string Brain::getType(void) const
{
    return _type;
}

void Brain::makeSound(void) const
{
    std::cout << "Makesound Brain called" << std::endl;
}