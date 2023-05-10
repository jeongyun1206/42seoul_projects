#include <string>

class Contact
{
    std::string first_name, last_name, nickname, phone_number, darkest_secret;
public:
    Contact() {};
    void        setting_Contact_info(std::string first_name, 
                                    std::string last_name, 
                                    std::string nickname, 
                                    std::string phone_number, 
                                    std::string darkest_secret);
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_number();
    std::string get_darkest_secret();
};

class PhoneBook
{
    int     add_index;
    int     book_size;
    Contact contacts[8];
    void    formatting_str(std::string str);
public:
    PhoneBook();
    void    add();
    void    search();
};