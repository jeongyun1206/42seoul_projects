#include "Zombie.hpp"
#include <iostream>

Zombie* Zombie::newZombie(std::string name)
{
    Zombie* new_zombie_ptr;

    new_zombie_ptr = new Zombie;
    new_zombie_ptr->name = name;
    return (new_zombie_ptr);
}