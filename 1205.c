#include <stdio.h>

// 如果其余的糖果能插入到最多的糖果中，则 yes，否则 no

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        unsigned long long max = 0, sum = 0;
        int n; scanf("%d", &n);
        while (n--) {
            int temp; scanf("%d", &temp);
            sum += temp;
            if (temp > max)
                max = temp;
        }
        if ((max - 1) > (sum - max)) printf("No\n");
        else printf("Yes\n");
    }
}