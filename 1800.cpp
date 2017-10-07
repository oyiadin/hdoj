#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, t;
    map<int, int> mp;
    while (scanf("%d", &n)!=-1) {
        int max=0;
        while (n--) {
            scanf("%d", &t);
            ++mp[t];
        }
        for(auto it=mp.begin(); it!=mp.end(); ++it)
            if (it->second > max) max=it->second;
        printf("%d\n", max);
        mp.clear();
    }
}
