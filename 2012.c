#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    while (1) {
        int min, max; scanf("%d%d", &min, &max);
        if (min == 0 && max == 0) return 0;

        int flag = 1;
        int max_f = (fabs(max+0.5) > fabs(min+0.5)) ? abs(max) : abs(min)-1;

        for (int i = 0; i <= max_f; ++i) {
            int f = i*i + i + 41;
            for (int j = f-1; j > 1; --j)
                if (f % j == 0) flag = 0;
            if (!flag) {
                printf("Sorry\n");
                break;
            }
        }
        if (flag) printf("OK\n");
    }
}