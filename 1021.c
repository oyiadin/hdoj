#include <stdio.h>

const int table[] = {0, 0, 1, 0, 0, 0, 1, 0};
// 有规律，循环节为：1, 2, 3, 2, 2, 1, 3, 1

int main() {
    int i;
    while (scanf("%d", &i) == 1)
        printf("%s\n", table[i%8] ? "yes" : "no");
}
