#include <stdio.h>
#include <string.h>

int M[1001];
int MAX[1001];


int main() {
    int n;
    while (scanf("%d", &n) != -1 && n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", M+i);
        // data input end

        int max = -1;
        memcpy(MAX, M, sizeof(M));
        // init end

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (M[i] > M[j] && MAX[j] + M[i] > MAX[i])
                    MAX[i] = MAX[j] + M[i];
            }
            if (MAX[i] > max)
                max = MAX[i];
        }

        printf("%d\n", max);
    }
}