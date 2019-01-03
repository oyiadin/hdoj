#include <stdio.h>
#include <string.h>

#define w(x) printf("%d\n", (x))
#define max(a, b) ((a)>(b) ? (a) : (b))
#define min(a, b) ((a)<(b) ? (a) : (b))
#define max3(a, b, c) max(max(a, b), c)

int M[100002][12];
int *MAX = M[0];

int main() {
    int n;
    while (scanf("%d", &n) != -1 && n) {
        memset(M, 0, sizeof(M));
        int maxt = 0;
        for (int i = 0; i < n; ++i) {
            int x, t;
            scanf("%d%d", &x, &t);
            M[t][x] += 1;
            if (t > maxt) maxt = t;
        }
        // data input end

        for (int i = maxt-1; i >= 0; --i) {
            M[i][0] += max(M[i+1][0], M[i+1][1]);
            // printf("%d ", MAX[0]);
            for (int j = 1; j < 11; ++j) {
                M[i][j] += max3(M[i+1][j-1], M[i+1][j], M[i+1][j+1]);
                // printf("%d ", MAX[j]);
            }
            // puts("");
        }
        
        printf("%d\n", MAX[5]);
    }
}
