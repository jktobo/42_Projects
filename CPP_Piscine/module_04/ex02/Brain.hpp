#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        std::string Brain::getIdea(int num) const;
        ~Brain();
        
    private:
        std::string _ideas[100];
};
#endif