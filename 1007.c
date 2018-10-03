#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define how_many 50

#define min(a, b) (((a)>(b)) ? (b) : (a))
#define dis(a, b) (((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
// returns the power of distance

typedef struct {
    double x, y;
} Point;

Point ps[100001];


int cmpx(const void *a, const void *b) {
    return ((Point*)a)->x - ((Point*)b)->x;
}

int cmpy(const void *a, const void *b) {
    return ((Point*)a)->y - ((Point*)b)->y;
}


int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &ps[i].x, &ps[i].y);
        }

        double min_dis = dis(ps[0], ps[1]);

        qsort(ps, n, sizeof(Point), cmpx);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < min(i+1+how_many, n); ++j) {
                double temp_dis = dis(ps[i], ps[j]);
                if (temp_dis < min_dis)
                    min_dis = temp_dis;
            }
        }

        qsort(ps, n, sizeof(Point), cmpy);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < min(i+1+how_many, n); ++j) {
                double temp_dis = dis(ps[i], ps[j]);
                if (temp_dis < min_dis)
                    min_dis = temp_dis;
            }
        }

        printf("%.2lf\n", sqrt(min_dis) / 2);

    }
}