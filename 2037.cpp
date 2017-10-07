#include <iostream>
#include <algorithm>
using namespace std;

struct P {
    int begin, end;
};
P d[100];

bool cmp(P a, P b) {
    return a.end < b.end;
}

int main() {
    int n;
    while (cin >> n && n!=0) {
        for (int i=0; i<n; ++i) cin >> d[i].begin >> d[i].end;
        sort(d, d+n, cmp);
        int end=0, num=0;
        for (int i=0; i<n; ++i) if ((d[i].end>end)&&(d[i].begin>=end)) {
            ++num;
            end=d[i].end;
        }
        cout << num << endl;
    }
}
