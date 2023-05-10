#include <iostream>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    add_index = 0;
    book_size = 0;
}

void    PhoneBook::add()
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
    
    if (add_index == 8)
        add_index = 0;
    std::cout << "first name>>";
    std::cin >> first_name;
    std::cout << "last_name>>";
    std::cin >> last_name;
    std::cout << "nickname>>";
    std::cin >> nickname;
    std::cout << "phone_number>>";
    std::cin >> phone_number;
    std::cout << "darkest_secret>>";
    std::cin >> darkest_secret;
    contacts[add_index].setting_Contact_info(first_name, last_name, nickname, phone_number, darkest_secret);
    add_index++;
    if (book_size < 8)
        book_size++;
}

void    PhoneBook::formatting_str(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0,9) << ".";
    else
    {
        for (int i = 0; i < 10 - (int)str.length(); i++)
            std::cout << " ";
        std::cout << str;
    }
    std::cout << "|";
}

void    PhoneBook::search()
{
    std::cout << "|     index|first name| last name|  nickname|\n";
    for (int i = 0; i < book_size; i++)
    {
        std::cout << "|         " << i + 1 << "|";
        formatting_str(contacts[i].get_first_name());
        formatting_str(contacts[i].get_last_name());
        formatting_str(contacts[i].get_nickname());
        std::cout << "\n";
    }
    int idx;
    std::cout << "enter index : ";
    std::cin >> idx;
    std::cout << "first name     : ";
    std::cout << contacts[idx - 1].get_first_name() << "\n";
    std::cout << "last name      : ";
    std::cout << contacts[idx - 1].get_last_name() << "\n";
    std::cout << "nickname       : ";
    std::cout << contacts[idx - 1].get_nickname() << "\n";
    std::cout << "phone number   : ";
    std::cout << contacts[idx - 1].get_phone_number() << "\n";
    std::cout << "darkest secret : ";
    std::cout << contacts[idx - 1].get_darkest_secret() << "\n";
}
