#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
        printf("%.2f\n", sqrt(pow(x2-x1, 2)+pow(y2-y1, 2)));
}