#include <stdio.h>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        if (a == 0 && b == 0) return 0;
        int sum = 1;
        // 头铁直接上就行，快速幂都不用
        while (b--)
            sum = (sum * a) % 1000;
        printf("%d\n", sum);
    }
}