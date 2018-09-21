#include <stdio.h>

// 思路：f(n) 仅与 f(n-1) 和 f(n-2) 有关
// 如果相邻两个数形成的模式已经出现过，则找到了正确的循环节
// 照着循环节取个模即可

int main() {
    int a, b, n;
    while (scanf("%d%d%d", &a, &b, &n) == 3) {
        if (a==0 && b==0 && n==0) return 0;

        int T = 0, adjust = 0;
        int m[49] = {1, 1, 0};  // 数列
        int occur[7][7] = {0};  // 记录相邻两个数的模式是否已经出现过
        int pos[7][7] = {0};    // 记录此模式上次出现的地点，便于取循环节
        occur[1][1] = 1;

        if (n < 2) {
            printf("1\n");
            continue;
        }

        for (int i = 2; i < n; ++i) {
            m[i] = (a*m[i-1] + b*m[i-2]) % 7;
            // printf("m[%d]=%d\n", i, m[i]);
            if (occur[m[i-1]][m[i]]) {
                adjust = pos[m[i-1]][m[i]]; 
                T = i - pos[m[i-1]][m[i]] - 1;
                // printf("T=%d, adj=%d\n", T, adjust);
                break;
            }
            occur[m[i-1]][m[i]] = 1;
            pos[m[i-1]][m[i]] = i - 1;
        }
        printf("%d\n", T ? m[adjust+((n-1-adjust)%T)] : m[n-1]);
    }
}