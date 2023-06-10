#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre Animal can't be NULL!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor Animal with parameter called " << name << std::endl;
        _type = name;
    }
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor Animal called" << std::endl;
    _type = other._type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator Animal called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor Animal called" << std::endl;
}

std::string Animal::getType(void) const
{
    return _type;
}

// void Animal::makeSound(void) const
// {
//     std::cout << "Makesound Animal called" << std::endl;
// }