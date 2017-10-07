#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long t, n, temp;
    cin >> t;
    for (int i=0; i<t; ++i) {
        cin >> n;
        long long sum=0, max_candy=0;
        for(int j=0; j<n; ++j) {
            cin >> temp;
            sum += temp;
            max_candy = max(max_candy, temp);
        }
        cout << (((sum-max_candy)>=(max_candy-1)) ? "Yes" : "No" ) << endl;
    }
}
