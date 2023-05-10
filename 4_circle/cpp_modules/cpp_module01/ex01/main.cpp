#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie  *zombie_horde;
    int         size;
    std::string name;

    std::cout << "enter size : ";
    std::cin >> size;
    std::cout << "enter name : ";
    std::cin >> name;
    zombie_horde = zombieHorde(size, name);
    for (int i = 0; i < size; i++)
        zombie_horde[i].announce();
    delete [] zombie_horde;
}