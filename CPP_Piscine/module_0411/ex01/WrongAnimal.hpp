#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(const std::string& name);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string getType(void) const;
    void makeSound() const;

    protected:
        std::string _type;
};
#endif