#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    while ((cin >> a >> b >> n) && !(a==0 && b==0 && n==0)) {
        int m[24];
        m[0] = m[1] = 1;
        for (int i=2; i<=23; ++i)
            m[i] = (a*m[i-1] + b*m[i-2]) % 7;

        cout << m[(n-1)%24] << endl;
    }
}