#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double r, PI=3.1415927;
    while (scanf("%lf", &r) != -1)
        printf("%.3lf\n", (4/3.0)*PI*pow(r, 3));
}
