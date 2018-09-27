#include <stdio.h>

#define w(x)
//printf(#x " = %d\n", (x))

int unit_price[1001], total[1001];

int main() {
    int c; scanf("%d", &c);
    while (c--) {
        int n, m; scanf("%d%d", &n, &m);
        w(n);
        w(m);
        char is_sold[1001] = {0};
        double sum = 0;

        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &unit_price[i], &total[i]);
            if (total[i] == 0) is_sold[i] = 1;
            if (unit_price[i] == 0) {
                sum += total[i];
                is_sold[i] = 1;
            }
        }

        if (m == 0) {
            printf("%.2lf\n", sum);
            continue;
        }

        while (n) {
            int i;
            int min_at = 0, min_price = 0;
            for (i = 0; i < m; ++i) if (!is_sold[i]) {
                min_at = i;
                min_price = unit_price[i];
                break;
            }

            for (; i < m; ++i) {
                if (!is_sold[i] && unit_price[i] < min_price) {
                    min_price = unit_price[i];
                    min_at = i;
                }
            }

            is_sold[min_at] = 1;

            if (n >= unit_price[min_at] * total[min_at]) {
                n -= unit_price[min_at] * total[min_at];
                w(n);
                w(min_at);
                sum += total[min_at];
            } else {
                w(2);
                sum += (double) n / unit_price[min_at];
                break;
            }
        }

        printf("%.2lf\n", sum);

    }
}