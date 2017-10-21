// WA
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> kill;
    kill.reserve(5500);
    for (int i=1; i<=5477; ++i) kill.push_back(i*i);

    while (scanf("%d", &n) != -1) {
        int i;
        for (i=0; i<5477; ++i) {
            if (kill[i] >= n) break;
        }
        int ans;
        if (kill[i] == n) { ans = i+1; if (n+ans>=kill[i+1]) ++ans;}
        else { ans = i; if (n+ans>=kill[i]) ++ans; }

        printf("%d\n", n+ans);
    }
}

/****
    # What is it?

    # Problem Description
    Alice is a pupil and likes natural numbers very much. But she only know 1,2,...,100. Now she meet a problem. The problem is described like this: I delete the square numbers(1,4,9,16,25...) in the natural numbers(1,2,3,4,5...), then it will be 2,3,5,6,7,8,10...
    Now please tell me which one is the n-th smallest number of the remaining series. She cannot solve it. Could you help her?

    # Input
    There are multiple test cases. 
    Each test cases consists of a number n (0 < n < 30,000,000).

    # Output
    For each case, output the n-th smallest number.

    # Sample Input
    1
    2

    # Sample Output
    2
    3
****/