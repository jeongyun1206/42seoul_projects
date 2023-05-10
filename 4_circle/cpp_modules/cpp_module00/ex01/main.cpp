#include <iostream>
#include "phonebook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook   phonebook;
    while (1)
    {
        std::cout << "enter command:";
        std::cin >> cmd;
        if (cmd == "ADD")
            phonebook.add();
        else if (cmd == "SEARCH")
            phonebook.search();
        else if (cmd == "EXIT")
            return (0);
        else
            std::cout << "wrong command\n";
    }
}