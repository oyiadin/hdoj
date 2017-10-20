#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != -1) {
        bool found = false;
        int s[6] = {a / 100, b / 100, a / 10 % 10, b / 10 % 10, a % 10, b % 10};
        for (int n = a; n <= b; ++n) {
            int i = n / 100;
            int j = n / 10 % 10;
            int k = n % 10;
            if ((i*100 + j*10 + k) == (int) (pow(i, 3)+pow(j, 3)+pow(k, 3))) {
                if (found) printf(" ");
                printf("%d", i*100 + j*10 + k);
                found = true;
            }
        }
        if (!found) printf("no");
        printf("\n");
    }
}