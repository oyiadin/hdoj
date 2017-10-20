#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int i, a, b;
    double ans_even, ans_odd;
    while (scanf("%d%d", &a, &b) != -1) {
        ans_even = 0;
        ans_odd = 0;
        if (a > b) swap(a, b);
        for (int i = a; i <= b; ++i) {
            if (i & 1) ans_odd += pow(i, 3);
            else ans_even += pow(i, 2);
        }
        printf("%d %d\n", (int) ans_even, (int) ans_odd);
    }
}