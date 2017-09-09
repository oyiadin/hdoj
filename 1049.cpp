#include <iostream>

int main() {
    unsigned int n, u, d, at, min;
    while (std::cin >> n >> u >> d) {
        if (n==0) break;
        n--;

        at = u;
        min = 1;

        while (at<=n) {
            at += (u-d);
            min += 2;
        }
        std::cout << min << std::endl;
    }
}