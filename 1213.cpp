#include <iostream>
using namespace std;

inline int get_root(int i, int *root) {
    while (root[i] != 0) i = root[i];
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    int t, m, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int root[1001] = {0};
        int times[1001] = {1};
        while (m--) {
            cin >> a >> b;
            a = get_root(a, root);
            b = get_root(b, root);
            if (a==b) continue;
            if (times[a] < times[b]) { int i=a; a=b; b=i; }
            root[b] = a;
            times[a] += times[b];
        }
        //for (int i=1; i<=n; ++i) cout << root[i] << "/";
        int ans=0;
        for (int i=1; i<=n; ++i) if (root[i] == 0) ++ans;
        cout << ans << endl;
    }
}
