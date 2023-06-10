#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    Cat(const std::string& name);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();

    std::string getType(void) const;
    void makeSound() const;
};
#endif