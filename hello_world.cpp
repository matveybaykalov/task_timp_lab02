#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name); //here the user name is requested
    std::cout << "Hello, World from " << name << std::endl;
    return 0;
}

