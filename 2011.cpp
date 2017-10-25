#include <cstdio>
using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int n;
        scanf("%d", &n);
        double ans=0, sign=1;
        for (int i=1; i<=n; ++i) {
            ans += sign / i;
            sign = -sign;
        }
        printf("%.2f\n", ans);
    }
}