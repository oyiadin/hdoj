#include <iostream>
using namespace std;

int main() {
    int l, n, sum, t;
    cin >> l;
    for (int i1=1; i1<=l; ++i1) {
        cin >> n;
        sum = 0;
        for (int i2=1; i2<=n; ++i2) {
            cin >> t;
            sum += t;
        }
        cout << sum << endl;
        if (i1 != l) cout << endl;
    }
}
