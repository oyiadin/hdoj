#include <stdio.h>

int main() {
    int ns[100];
    while (1) {
        int n; scanf("%d", &n);
        if (!n) return 0;

        scanf("%d", ns);
        int smallest = ns[0], smallest_at = 0;
        for (int i = 1; i < n; ++i) {
            scanf("%d", ns+i);
            if (ns[i] < smallest) {
                smallest = ns[i];
                smallest_at = i;
            }
        }
        printf("%d", ns[smallest_at]);
        for (int i = 1; i < n; ++i) {
            if (i == smallest_at)
                printf(" %d", ns[0]);
            else
                printf(" %d", ns[i]);
        }
        printf("\n");
    }
}