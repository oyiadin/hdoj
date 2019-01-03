#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define min(a, b) ((a)<(b) ? (a) : (b))
#define sqr(x) ((x) * (x))

int M[2001];
int dp[2001][1001];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        for (int i = 0; i < n; ++i)
            scanf("%d", M+i);
        // data input ends

        qsort(M, n, sizeof(int), cmp);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                dp[i][j] = INT_MAX;
        for (int i = 0; i < n; ++i)
            dp[i][0] = 0;
        for (int j = 0; j < k; ++j)
            dp[0][j] = 0;
        // init end
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; 2*j <= min(i, 2*k); ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + sqr(M[i-2]-M[i-1]));
            }
        }
        
        printf("%d\n", dp[n][k]);
    }
}
