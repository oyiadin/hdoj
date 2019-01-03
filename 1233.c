#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define _memset(dest, data, type) \
    for (int i = 0; i < sizeof(dest)/sizeof(int); ++i) \
        dest[i] = data;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


typedef struct Edge {
    int e1, e2;
    int weight;
} Edge;

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}


Edge edges[5000];
int A[102], H[102];


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
    int n;
    while (scanf("%d", &n) == 1 && n) {
    memset(A, 0, sizeof(A));
    _memset(H, 1, int);

    int num_edges = n*(n-1)/2;
    for (int i = 0; i < num_edges; ++i) {
        int e1, e2, weight;
        scanf("%d%d%d", &e1, &e2, &weight);
        edges[i].e1 = e1;
        edges[i].e2 = e2;
        edges[i].weight = weight;
    }

    qsort(edges, num_edges, sizeof(Edge), cmp);
    int final_weight = 0;

    int at = 0;
    for (int i = 0; i < n-1; ++i) {
        while (1) {
            if (root(edges[at].e1) == root(edges[at].e2)) {
                at++;
                continue;
            } else {
                merge(edges[at].e1, edges[at].e2);
                final_weight += edges[at].weight;
                at++;
                break;
            }
        }
    }

    printf("%d\n", final_weight);
    }
}
