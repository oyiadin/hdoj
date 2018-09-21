#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, raw_n, sum = 1;
        scanf("%d", &n);
        raw_n = n;
        n %= 10;

        // 快速幂+取模
        // 理解了原理就挺好写的
        while (raw_n) {
            if (raw_n & 1) sum = (sum * n) % 10;
            raw_n >>= 1;
            n = (n * n) % 10;
        }
        printf("%d\n", sum);
    }
}