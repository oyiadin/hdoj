#include <stdio.h>
#include <stdlib.h>
#include <stack>
// emmm, sorry for using cpp and c in the meantime

#define _memset(dest, data, type) \
    for (int i = 0; i < sizeof(dest)/sizeof(type); ++i) \
        dest[i] = data;

typedef struct mouse {
    int weight;
    int speed;
    int ID;
} mouse;

mouse mouses[1001];
int dp[1001], prev[1001];

int cmp(const void *a, const void *b) {
    return ((mouse *)a)->weight - ((mouse *)b)->weight;
}

int main() {
    int w, s, n=0;
    while (scanf("%d%d", &w, &s) == 2) {
        mouses[n].weight = w;
        mouses[n].speed = s;
        mouses[n].ID = n+1;
        n++;
    }

    qsort(mouses, n, sizeof(mouse), cmp);
    _memset(dp, 1, int);
    _memset(prev, -1, int);

    int max_dp_index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mouses[j].weight < mouses[i].weight && mouses[j].speed > mouses[i].speed) {
                if (dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                    if (dp[i] > dp[max_dp_index])
                        max_dp_index = i;
                }
            }
        }
    }

    printf("%d\n", dp[max_dp_index]);
    int index = max_dp_index;
    std::stack<int> stk;

    while (index != -1) {
        stk.push(mouses[index].ID);
        index = prev[index];
    }

    while (!stk.empty())
        printf("%d\n", stk.top()), stk.pop();
}