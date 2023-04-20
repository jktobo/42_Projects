
#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "foo";
}

Zombie::~Zombie()
{
    std::cout << name << " was deleted!" << std::endl;
}

Zombie::Zombie(std::string a_name)
{
    name = a_name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

