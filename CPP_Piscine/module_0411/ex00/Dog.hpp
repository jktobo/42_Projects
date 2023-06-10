#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
    Dog();
    Dog(const std::string& name);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    std::string getType(void) const;
    void makeSound() const;
};
#endif