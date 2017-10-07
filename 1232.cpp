#include <cstdio>
using namespace std;

inline int get_root(int i, int *to) {
	while (to[i]!=0) i=to[i];
	return i;
}

int main() {
	int n, m, a, b;
	while(scanf("%d", &n) && n) {
		scanf("%d", &m);
		int to[1001]={0}, size[1001]={1};
		while (m--) {
			scanf("%d%d", &a, &b);
			a = get_root(a, to);
			b = get_root(b, to);
			if (a==b) continue;
			if (size[b] < size[a]) { int i=a; a=b; b=i; }
			to[a] = b;
			size[b] += size[a];
		}
		int ans=-1;
		for (int i=1; i<=n; ++i) if (to[i]==0) ++ans;
		printf("%d\n", ans);
	}
}