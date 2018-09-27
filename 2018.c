#include <stdio.h>
#define w(x) printf(#x "=%d\n", x)

int main() {
    int ds[55] = {1, 2, 3, 4};
    int n;

    for (int i = 4; i < 55; ++i)
        ds[i] = ds[i-1]+ds[i-3];

    /*
    for (int i = 0; i < 20; ++i) {
        printf("%d => %d\n", i+1, ds[i]);
    }
    */

    while (scanf("%d", &n) == 1) {
        if (n == 0) return 0;
        printf("%d\n", ds[n-1]);
    }
}
