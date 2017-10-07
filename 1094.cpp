#include <iostream>
using namespace std;

int main() {
    int n, t, sum;
    while (cin >> n) {
        sum = 0;
        for (int i=1; i<=n; i++) {
            cin >> t;
            sum += t;
        }
        cout << sum << endl;
    }
}
