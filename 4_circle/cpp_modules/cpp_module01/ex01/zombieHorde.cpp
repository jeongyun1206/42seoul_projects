#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombie_arr;

    zombie_arr = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombie_arr[i].setName(name);
    return (zombie_arr);
}