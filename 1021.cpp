#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if ((n%4==0)||(n%4==1)||(n%4==3)) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}
