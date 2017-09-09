#include <iostream>

int main() {
    while (1) {
        unsigned int items, i, to, at=0, sec_total=0;
        std::cin >> items;
        if (items==0) break;

        for (i=1; i<=items; i++) {
            std::cin >> to;
            if (to>at) sec_total+=6*(to-at);
            else sec_total+=4*(at-to);
            sec_total += 5;
            at = to;
        }
        std::cout << sec_total << std::endl;
    }
}