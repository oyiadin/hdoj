#include <cstdio>
using namespace std;

int main() {
    int n;
    while ((scanf("%d", &n) != -1) && n != 0) {
        double t;
        int minus = 0, zero = 0, posi = 0;
        while (n--) {
            scanf("%lf", &t);
            if (t < 0) ++minus;
            else if (t == 0) ++zero;
            else ++posi;
        }
        printf("%d %d %d\n", minus, zero, posi);
    }
}