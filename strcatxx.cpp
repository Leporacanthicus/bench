#include <string>
#include <iostream>

std::string longstr;

int main()
{
    std::string str;
    while(std::cin >> str)
    {
	longstr += str;
    }
    std::cout << longstr << std::endl;
}
