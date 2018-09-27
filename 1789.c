#include <stdio.h>
#include <stdlib.h>

#define w(x)
// printf(#x " = %d\n", (x))

typedef struct Subject {
    int deadline, penalty;
} Subject;

Subject subjects[1001];


int cmp (const void *a, const void *b) {
    return ((Subject *)b)->penalty - ((Subject *)a)->penalty;
    // 降序
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int total_penalty = 0;
        char is_arranged[1001] = {0};

        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &subjects[i].deadline);
        for (int i = 0; i < n; ++i)
            scanf("%d", &subjects[i].penalty);

        qsort(subjects, n, sizeof(Subject), cmp);

        for (int i = 0; i < n; ++i) {
            int deadline = subjects[i].deadline;
            int penalty = subjects[i].penalty;
            w(penalty);
            w(deadline);

            char flag = 0;
            for (int j = deadline; j > 0; --j) {
                if (!is_arranged[j-1]) {
                    is_arranged[j-1] = 1;
                    flag = 1;
                    break;
                }
            }
            if (!flag) total_penalty += penalty;
        }

        printf("%d\n", total_penalty);
    }
}