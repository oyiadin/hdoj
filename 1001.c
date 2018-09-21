#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        if (n % 2)  // 奇数
        	printf("%d\n\n", (1+n)/2*n);
        else  // 偶数
        	printf("%d\n\n", n/2*(n-1)+n);
    }
}
