// TLE
#include <cstdio>
using namespace std;

int main() {
    int t, n, ans;
    while (scanf("%d", &t) != -1) {
        while (t--) {
            ans = 1;
            scanf("%d", &n);
            for (int i=1; i<=(n/2)+1; ++i) if (n%i==0) {
                ans = (ans*(i%10007))%10007;
            }
            printf("%d\n", ans);
        }
    }
}

/****
    # Just multiply it

    # Problem Description
    This is a easy problem.
    Given an integer, you just need calculate the product of all it's factors.

    For example:
    The factors of 9 are 1 and 3, so the product of it's factors is: 1 * 3 = 3
    The factors of 12 are 1,2,3,4 and 6, so the product of it's factors is: 1 * 2 * 3 * 4 * 6 = 144
    ......

    # Input
    First given a positive integer T(T <= 100000), which indicates the number of test cases.
    For each case, there is an integer n( 2 <= n <= 1000000).

    # Output
    Please calculate the product of the factors, and output the result mod 10007.

    # Sample Input
    3
    9
    10
    12

    # Sample Output
    3
    10
    144
****/