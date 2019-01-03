#include <stdio.h>
#include <string.h>
#define w(x) printf("%d\n", (x))
#define max(a, b) ((a)>(b) ? (a) : (b))


int M[101][101] = {0};
int MAX[101] = {0};

int main() {
    int c; scanf("%d", &c);
    while (c--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= i; j++)
                scanf("%d", &M[i][j]);
        // data input end

        memcpy(MAX, M[n-1], sizeof(M[n-1]));
        // init
        
        for (int i = n-2; i >= 0; --i) {
            // printf("i=%d\n", i);
            for (int j = 0; j < i+1; ++j) {
                MAX[j] = max(MAX[j], MAX[j+1]) + M[i][j];
                // printf("MAX[%d] = %d\n", j, MAX[j]);
            }
        }

        printf("%d\n", MAX[0]);
    }
}
