#include <iostream>
using namespace std;

int main() {
    int t;
    long long a, b, ans;
    cin >> t;
    for (int i=0; i<t; ++i) {
        ans=1;
        cin >> a;
        b = a;
        a%=10;
        while(b) {
            if(b&1) ans=(ans*a)%10;
            b>>=1;
            a=(a*a)%10;
        }
        cout << ans << endl;
    }
}
