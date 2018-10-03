#include <stdio.h>
#include <stdlib.h>

int degrees[1001];

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

void func() {
    int sum = 0, blank = 0;
    int n; scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", degrees+i);

    for (int i = 0; i < n; ++i) {
        qsort(degrees+i, n-i, sizeof(int), cmp);

        if (degrees[i] > n-i-1 || degrees[i] < 0) {
            printf("no\n");
            return;
        }
        for (int j = 1; j <= degrees[i]; ++j) {
            --degrees[i+j];
        }
    }

    printf("yes\n");
}


int main() {
    int t; scanf("%d", &t);
    while (t--) {
        func();
    }
}