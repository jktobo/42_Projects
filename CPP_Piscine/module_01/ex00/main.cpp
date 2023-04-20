
#include "Zombie.hpp"

int main(void)
{
    Zombie foo;
    foo.announce();

    Zombie *first = newZombie("Heap");
    first->announce();
    delete(first);

    randomChump("Stack");

    return (0);
}