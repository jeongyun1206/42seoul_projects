#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    this->name = "no_named";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout << name << " dead\n";
}
