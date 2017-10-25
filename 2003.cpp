#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double i;
    while (scanf("%lf", &i) != -1)
        printf("%.2lf\n", abs(i));
}