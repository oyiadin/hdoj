#include <cstdio>
using namespace std;

int main() {
    int t, n, s, d;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int f[205];
        for (int i=0; i<=200; ++i) f[i]=0;
        while(n--) {
            scanf("%d%d", &s, &d);
            if(s>d){int o=s; s=d; d=o;}
            s=(s-1)/2;
            d=(d-1)/2;
            for(int i=s; i<=d; ++i) f[i]++;
        }
        int max=0;
        for (int i=0; i<200; ++i) if(f[i]>max) max=f[i];
        printf("%d\n", max*10);
    }
}
