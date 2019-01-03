#include <stdio.h>
#include <stdlib.h>

int hs1[1001], hs2[1001];
// tian, king



int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; ++i)
            scanf("%d", hs1+i);
        for (int i = 0; i < n; ++i)
            scanf("%d", hs2+i);

        int earn = 0;

        qsort(hs1, n, sizeof(int), cmp);
        qsort(hs2, n, sizeof(int), cmp);

        int l1=0, r1=n-1, l2=0, r2=n-1;
        while (l1 <= r1 && l2 <= r2) {
            if (hs1[l1] < hs2[l2]) {
                // 如果田忌最弱的马比齐王最弱的马还要弱，
                // 那么这匹马必输，直接与齐王最强的马进行比赛
                ++l1;
                --r2;
                earn -= 200;

            } else if (hs1[l1] > hs2[l2]) {
                // 如果齐王最弱的马比田忌最弱的马还要弱
                // 那么这匹马必输，直接与田忌最弱的马进行比赛
                ++l1;
                ++l2;
                earn += 200;

            } else {
                // 现在两者最弱的马跑得一样快，需继续判断
                if (hs2[r2] > hs1[r1]) {
                    // 如果齐王最快的马比田忌最快的马还要快，
                    // 那么齐王的这匹马必赢，直接与田忌最弱的马进行比赛
                    ++l1;
                    --r2;
                    earn -= 200;
                } else if (hs1[r1] > hs2[r2]) {
                    // 如果田忌最快的马比齐王最快的马还要快，
                    // 直接比赛即可
                    --r1;
                    --r2;
                    earn += 200;
                } else {
                    // 此时田忌、齐王最快、最弱的马都分别一样快
                    // 用田忌最弱的马与齐王最快的马进行比赛
                    // 平局情况下，怎么选都无所谓
                    // 非平局的情况下，就算本局输了(用以打破僵局)，下一轮肯定能赢
                    // 而且以最小的马挑战齐王最强的马，可以为后续赛局带来优势
                    if (hs1[l1] < hs2[r2])
                        earn -= 200;
                    ++l1;
                    --r2;
                }
            }
        }

        printf("%d\n", earn);
    }
}