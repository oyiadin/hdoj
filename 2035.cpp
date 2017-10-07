#include <iostream>
using namespace std;

int main() {
    int a, b, ans;
    while((cin >> a >> b) && a!=0 && b!=0) {
        ans=1;
        a%=1000;
        while (b) {
            if (b&1) ans = (ans*a)%1000;
            b>>=1;
            a=(a*a)%1000;
        }
        cout << ans << endl;
    }
}
