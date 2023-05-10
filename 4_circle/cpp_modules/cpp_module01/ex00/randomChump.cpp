#include "Zombie.hpp"
#include <iostream>

void    Zombie::randomChump(std::string name)
{
    Zombie  zombie;

    zombie.name = name;
    zombie.announce();
}