#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;

        int sum = 5 * n;
        int prev = 0, dest;

        while (n--) {
            scanf("%d", &dest);
            int delta = dest - prev;
            prev = dest;

            if (delta > 0) {
                sum += 6 * delta;
            } else if (delta < 0) {
                sum += -4 * delta;
            } else {
                // sum -= 5;
            }
        }
        printf("%d\n", sum);
    }
}