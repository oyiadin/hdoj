#include <stdio.h>

#define w(x)


int J[1001], P[1001];
double unit_price[1001];


int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) == 2) {
        if (m == -1 && n == -1) return 0;
        double sum = 0;
        char is_sold[1001] = {0};

        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &J[i], &P[i]);
            if (P[i] == 0) {
                is_sold[i] = 1;
                sum += J[i];
                continue;
            }
            unit_price[i] = (double) P[i] / J[i];
            w(unit_price[i]);
        }

        if (n == 0) {
            printf("%.3lf\n", sum);
            continue;
        }

        while (m) {
            double min_unit_price = 0;
            int min_at = 0, i;
            for (i = 0; i < n; ++i) if (!is_sold[i]) {
                min_unit_price = unit_price[i];
                min_at = i;
                break;
            }

            for (;i < n; ++i) {
                if (!is_sold[i]) {
                    if (unit_price[i] < min_unit_price) {
                        min_unit_price = unit_price[i];
                        min_at = i;
                    }
                }
            }

            w(P[min_at]);

            if (m >= P[min_at]) {
                m -= P[min_at];
                sum += J[min_at];
                w(J[min_at]);
                is_sold[min_at] = 1;
            } else {
                w(J[min_at] * ((double) m / P[min_at]));
                sum += J[min_at] * ((double) m / P[min_at]);
                break;
            }
        }

        printf("%.3lf\n", sum);
    }
}