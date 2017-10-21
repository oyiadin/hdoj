// AC
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned long long a, b;
    while (cin >> a >> b) {
        if (a>b) swap(a, b); 
        cout << (b-a)+1 << endl;
    }
}

/****
    # Pyramid

    # Problem Description
    The pyramid is made up of many rectangular stones. The upstairs stone can only put on the center of four downstairs stones. 
    Can you tell me how many stones on the top of pyramid ?

    [image here]

    # Input
    Each line contains two non-negative integers A and B(A, B < 2^64), A*B represents the size of bottom stairs of pyramid. 
    Process to end of file.

    # Output
    For each case, output the number of stones on the top stairs of pyramid.

    # Sample Input
    4 6

    # Sample Output
    3
****/