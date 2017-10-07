#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int t;
    if(b>a) {t=a; a=b; b=t;}
    while(t=a%b) {
        a=b;
        b=t;
    }
    return b;
}

int main() {
    int a, b, t;
    while(cin >> a >> b) cout << (a*b)/gcd(a, b) << endl;
}
