#include "Zombie.hpp"

int main(void)
{
    Zombie a, b("B");
    a.announce();
    b.announce();
    Zombie *c;
    c = a.newZombie("C");
    c->announce();
    delete c;
    a.randomChump("D");
}