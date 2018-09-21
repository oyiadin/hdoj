#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        int mul = a * b;
        if (b) while ((a %= b) && (b %= a));
        int gcd = a + b;
        printf("%d\n", mul / gcd);
    }
}