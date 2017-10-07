#include <iostream>
using namespace std;

int main() {
    int a, b, ans;
    while(cin >> a >> b) {
        ans=1;
        a%=10;
        while (b) {
            if (b&1) ans = (ans*a)%10;
            b>>=1;
            a=(a*a)%10;
        }
        cout << ans << endl;
    }
}
