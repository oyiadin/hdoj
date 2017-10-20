#include <cstdio>
using namespace std;

int main() {
    int n, t, ans = 1;
    while (scanf("%d", &n) != -1) {
        ans = 1;
        while (n--) {
            scanf("%d", &t);
            if (t & 1) ans *= t;
        }
        printf("%d\n", ans);
    }

}