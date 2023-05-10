#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        for (int j = 0; j < (int)str.length(); j++)
            str[j] = toupper(str[j]);
        std::cout << str;
    }
    std::cout << std::endl;
}