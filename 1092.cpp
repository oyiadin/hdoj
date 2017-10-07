#include <iostream>
using namespace std;

int main() {
    int n, sum, t;
    while ((cin >> n) && (n!=0)) {
        sum = 0;
        for (int i=1; i<=n; i++) {
            cin >> t;
            sum += t;
        }
        cout << sum << endl;
    }
}
