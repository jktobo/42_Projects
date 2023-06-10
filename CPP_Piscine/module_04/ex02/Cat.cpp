#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(const std::string& name)
{
    if (name.empty())
        std::cout << "The parametre Cat can't be empty!" << name << std::endl;
    else
    {
        std::cout << "Constructor Animal with parameter called " << name << std::endl;
        _type = name;
    }
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy constructor Cat called " << std::endl;
    // _type = other._type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator Cat called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "MYEOYY!" << std::endl;
}