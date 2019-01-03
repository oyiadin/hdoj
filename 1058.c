#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define min(a, b) ((a) > (b) ? (b) : (a))
#define min3(a, b, c) (min(a, b) > (c) ? (c) : min(a, b))
#define min4(a, b, c, d) (min3(a, b, c) > (d) ? (d) : min3(a, b, c))

const char st[] = "st";
const char nd[] = "nd";
const char rd[] = "rd";
const char th[] = "th";
long long dp[5843] = {0};
// f[t] = min(2*f[p2], 3*f[p3], 5*f[p5], 7*f[p7])

int main() {
    int n;
    int count = 1;
    dp[count] = 1;
    
    long long p2=1, p3=1, p5=1, p7=1;

    while (count++ < 5843) {
        dp[count] = min4(2*dp[p2], 3*dp[p3], 5*dp[p5], 7*dp[p7]);
        
        while (2*dp[p2] <= dp[count]) ++p2;
        while (3*dp[p3] <= dp[count]) ++p3;
        while (5*dp[p5] <= dp[count]) ++p5;
        while (7*dp[p7] <= dp[count]) ++p7;
    }
    
    while (scanf("%d", &n) == 1 && n) {
        const char *suffix;
        switch (n % 10) {
            case 1: suffix = st; break;
            case 2: suffix = nd; break;
            case 3: suffix = rd; break;
            default:
                suffix = th;
        }
        switch (n % 100) {
            case 11:
            case 12:
            case 13: suffix = th; break;
        }
        
        printf("The %d%s humble number is %lld.\n",
               n, suffix, dp[n]);
    }
}
