#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int ori_pos;
} NB;


int cmp(const void *a, const void *b) {
    return ((NB *)b)->num - ((NB *)a)->num;
}

void func() {
    NB nb[11];
    int mat[10][10] = {0};

    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nb[i].num);
        nb[i].ori_pos = i;
    }

    for (int i = 0; i < n; ++i) {
        qsort(nb+i, n-i, sizeof(NB), cmp);

        if (nb[i].num > n-i-1 || nb[i].num < 0) {
            printf("NO\n");
            return;
        }

        for (int j = 1; j <= nb[i].num; ++j) {
            int _i = nb[i].ori_pos;
            int _j = nb[i+j].ori_pos;
            mat[_i][_j] = mat[_j][_i] = 1;
            --nb[i+j].num;
        }
    }

    printf("YES\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != n-1) printf("%d ", mat[i][j]);
            else printf("%d\n", mat[i][j]);
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        func();
        if (t) printf("\n");
    }
}
