// WA
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t, m, a, b, c, d;
    double rate1, rate2;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &m);
        int ans = 0;

        scanf("%d%d%d%d", &a, &b, &c, &d);
        rate1 = a / (double)b;
        rate2 = c / (double)d;
        if ((rate1 - rate2)>1e-6) {
            swap(a, c); swap(b, d);
        }

        while (m && m >= a) { ans += b; m -= a; }
        while (m && m >= c) { ans += d; m -= c; }
        printf("%d", ans);
        if (t!=0) printf("\n");
    }
}

/****
    # MouGe's Chicken legs

    # Problem Description
    Almost everybody have ever taken the train,but have you taken a long-distance train? There are some salesmen on the long-distance train saling their food or souvenirs,and MouGe is one of them.
    Suppose you were on a train , and now MouGe comes again with some chicken legs, he will pass through your seat twice,and each time the price he sales his chicken legs is different. When MouGe come,the price is A yuan for B chicken leg(s) and when he goes it is C yuan for D chicken leg(s).You have M yuan,how many chicken legs can you buy most?(Suppose MouGe has infinite chicken legs)

    # Input
    The first line contains an integer T, which indicates the number of test cases.
    Each test case contains an integer M(0<M<=10^6) on the first line, that means the money you have on the first line, and followed by 4 integers A,B,C,D(0<a,b,c,d<=1000) on the second line.

    # Output
    For each test case, please output the number of the chicken legs that you can buy most.

    # Sample Input
    2
    5
    3 3 4 1
    3
    1 2 2 5

    # Sample Output
    3
    7

    # Hint
    In case 1: you can use 3 yuan and by 3 chicken legs
    In case 2: at the first time,you can use 1 yuan to by 2 chicken legs,then use 2 yuan to buy 5 chicken legs
****/