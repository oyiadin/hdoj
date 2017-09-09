#include <iostream>
#include <string>

int main() {
    std::string input = "";
    int a = 0, b = 0;

    while(std::cin >> a >> b) 
        std::cout << a + b << std::endl;

    return 0;
}