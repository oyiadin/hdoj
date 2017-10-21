// AC
#include <cstdio>
using namespace std;

int main() {
    unsigned i, high, low;
    while (scanf("%d", &i) != -1) {
        high = i & 0xFFFF0000;
        low = i & 0x0000FFFF;
        printf("%u\n", (high>>16)+(low<<16));
    }
}

/****
    # Alice's Problem

    # Problem Description
    This term Alice and Bob has one course named "C programming".

    This class Mr Lee told them that the unsigned int in C language is a 32-bit integer. That means a unsigned int stored in memory occupied 32 bits. For example, 2147483648(231) stored in memory as 10000000000000000000000000000000, and 4294967295(232-1) stored in memory as 11111111111111111111111111111111.

    After Alice heard that, She stopped play his iphone 4s and was lost in thought: "What's the number If I take the first 16-bit to the behind of the last 16-bit? " 
    Unfortunately, the number was so large that Alice was unable to calculate... So she had to turn to you. Could you help her to calculate it?

    # Input
    The input contains multiple test cases (No more than 100).
    Each case contains a line with a unsigned number.

    # Output
    You should output one line with the correct number Alice wanted to known.

    # Sample Input
    0
    41
    32768

    # Sample Output
    0
    2686976
    2147483648
****/