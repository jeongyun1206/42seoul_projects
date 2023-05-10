#include <string>

class Zombie
{
    std::string name;
public:
    void    announce(void);
    Zombie* newZombie(std::string name);
    void    randomChump(std::string name);
    Zombie();
    Zombie(std::string name);
    ~Zombie();
};