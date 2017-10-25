#include <cstdio>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != -1) {
        double in, ans = 0, max = 0, min = 101;
        for (int i=0; i<n; ++i) {
            scanf("%lf", &in);
            ans += in;
            max = (in > max) ? in : max;
            min = (in < min) ? in : min;
        }
        printf("%.2f\n", (ans-max-min)/(n-2));
    }
}