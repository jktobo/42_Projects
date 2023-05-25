#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& name)
{
    std::cout << "Constructor WrongAnimal with parameter called " << name << std::endl;
    _type = name;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "Copy constructor WrongAnimal called" << std::endl;
    _type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Copy assignment operator WrongAnimal called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return _type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Makesound WrongAnimal called" << std::endl;
}