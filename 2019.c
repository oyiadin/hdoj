#include <stdio.h>
#define w(x) printf(#x "=%d\n", x)

int list[101];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        if (n == 0 && m == 0) return 0;

        int flag = 0;
        int x; scanf("%d", &x);
        if (x > m) {
            printf("%d %d", m, x);
            flag = 1;
        } else {
            printf("%d", x);
        }

        while (--n) {
            scanf("%d", &x);
            if (!flag && x > m) {
                printf(" %d %d", m, x);
                flag = 1;
            } else printf(" %d", x);
        }

        if (!flag) printf(" %d\n", m);
        else printf("\n");
    }
}
