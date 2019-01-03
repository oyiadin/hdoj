#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _memset(dest, data, type) \
    for (int i = 0; i < sizeof(dest)/sizeof(int); ++i) \
        dest[i] = data;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


int A[1002], H[1002];

int root(int x) {
    while (A[x]) x = A[x];
    return x;
}

void merge(int a, int b) {
    int root_a = root(a);
    int root_b = root(b);
    if (root_a == root_b)
        return;

    if (H[root_a] >= H[root_b]) {
        A[root_b] = root_a;
        H[root_a] = max(H[root_a], H[root_b]+1);
    } else {
        A[root_a] = root_b;
        H[root_b] = max(H[root_b], H[root_a]+1);
    }
}

int main() {
    int n, m;
    while (scanf("%d", &n) == 1 && n != 0) {
        scanf("%d", &m);

        memset(A, 0, sizeof(A));
        _memset(H, 1, int);

        while (m--) {
            int a; scanf("%d", &a);
            int b; scanf("%d", &b);
            merge(a, b);
        }

        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (A[i] == 0)
                count++;
        }
        printf("%d\n", count-1);
    }
}
