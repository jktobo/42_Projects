#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(const std::string& name)
{
    if (name.empty())
    {
        std::cout << "The parametre Dog can't be empty!" << name << std::endl;
    }
    else
    {
        std::cout << "Constructor Animal with parameter called " << name << std::endl;
        _type = name;
    }
}

Dog::Dog(const Dog& other)
{
    std::cout << "Copy constructor Dog called" << std::endl;
    _type = other._type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator Dog called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "WOOF!" << std::endl;
}