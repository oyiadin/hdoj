// AC
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t, n, m;
    bool blocked[500];
    string line;
    cin >> t;
    int at = 0;
    while (t-- && ++at) {
        int ans = 1;
        cin >> n >> m;
        for (int i=0; i<m; ++i) blocked[i]=0;

        while (n--) {
            cin >> line;
            bool flag = 1;
            bool empty = 1;
            /* bool full = 1; */  // 即便数据有某行是满的也要 ++ans
            for (int i=0; i<m; ++i) {
                if (line[i] == '#') { blocked[i]=1; empty=0; }
                else { /* full = 0; */
                    if (blocked[i]) { flag=0; /* break; */ }  // 后边的数据不可丢弃！
                }
            }
            if (flag && !empty /* && !full */) ++ans;
        }
        printf("Case %d: %d\n", at, ans);
    }
}

/****
    # Heaven Tetris

    # Problem Description
    Amb likes playing Tetris very much. After he has played the Tetris several days, the god comes.

    [image here]

    The god likes to play Tetris too. He is moved by Amb. So he awards Amb a super block. This block can help Amb clean as more lines as possible. And there is one and only one full line at the top of the super block just like the picture above. It is because the god wants to prevent Amb from moving the block to a wrong place. How kind the god is! Can you tell him how many lines this block can clean for Amb?
    Don’t tell me you don’t know how to play Tetris. The god will get angry.

    # Input
    In the first line there is an integer T (T <= 20), indicates the number of test cases.
    In each case, the first line contains two integers n and m (2 <= n, m <= 500), which is the size of the board. Then n lines follow, each contains m characters. The ‘.’ represents an empty block. And the ‘#’ represents a full block.
    All the input is legal. And you can assume there is at least one blank line between the highest given block(s) and the top.

    # Output
    For each case, the output format is “Case c: ans”. 
    c is the case number start from 1.
    ans is the answer of this problem.

    See the sample for more details. If you can’t get the sample, don’t forget the top line of the super block.

    # Sample Input
    2
    5 10
    ..........
    #..#......
    ##.#.#....
    #######...
    #######.##
    6 10
    ..........
    ..........
    #..####...
    ######....
    ..#####...
    #####.#.##

    # Sample Output
    Case 1: 5
    Case 2: 2
****/