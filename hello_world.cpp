#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name); //здесь запрашивается имя у пользователя
    std::cout << "Hello, World from " << name << std::endl;
    return 0;
}

