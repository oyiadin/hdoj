#include <stdio.h>
#include <math.h>

int main() {
    double n; int m;
    while (scanf("%lf%d", &n, &m) == 2) {
        double sum = n;
        while (--m) {
            n = sqrt(n);
            sum += n;
        }
        printf("%.2lf\n", sum);
    }
}