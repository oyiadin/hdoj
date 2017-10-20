#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int y, m, d;
    int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    while(scanf("%d/%d/%d", &y, &m, &d) != -1) {
        int ans = 0;
        ans += days[(int)ceil(m)-1];
        ans += d;
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
            if (m > 2) ++ans;
        printf("%d\n", ans);
    }
}