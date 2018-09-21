#include <stdio.h>

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int lcm; scanf("%d", &lcm);
        // 保证至少一个数，所以先读一个放到 lcm 里
        while (--n) {
            int input; scanf("%d", &input);
            int temp1 = lcm, temp2 = input;
            while ((temp1 %= temp2) && (temp2 %= temp1)) ;
            int gcd = temp1 + temp2;
            // 这样算 gcd 又好记又精简，感谢 wikipedia
            lcm = lcm / gcd * input;
        }
        printf("%d\n", lcm);
    }
}