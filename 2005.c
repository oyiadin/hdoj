#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int g = n / m, remains = n % m;

        for (int i=0; i < g; ++i) {
            if (i == g-1 && !remains)
                printf("%d\n", 2*i*m+m+1);
            else
                printf("%d ", 2*i*m+m+1);
        }
        if (remains) {
            printf("%d\n", 2*g*m+remains+1);
        }
    }
}
