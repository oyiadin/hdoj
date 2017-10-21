// AC
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, a, b, c, d;
    scanf("%d", &t);
    int like[10000];
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            like[i] = 0;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (a>1000 || b<20 || c<40) like[d-1] = 0;
            else {
                like[d-1] = (1000-a) + (b-20) + (c-40);
            }
        }
        int max = 0;
        vector<int> maxes;
        for (int i=0; i<n; ++i) {
            if (like[i] > max) {
                max = like[i];
                maxes.clear();
                maxes.push_back(i+1);
            } else if (like[i] == max) {
                maxes.push_back(i+1);
        }}
        sort(maxes.begin(), maxes.end());
        for (vector<int>::iterator i=maxes.begin(); i!=maxes.end(); ++i)
            if (i==maxes.begin()) printf("%d", *i);
            else printf(" %d", *i);
        printf("\n");
    }
}

/****
    # 租房子

    # Problem Description
    Jfx已经大四，马上准备去实习了，可是如果住在学校天天挤公交车真的是很操蛋的一件事——所以，jfx决定租房子住。但是可选择的房子太多了，而且jfx有自己的癖好，所以现在jfx请你帮他选择哪个或者哪几个房子是他想要租的。

    Jfx租房考虑3个因素：租金，房间大小，新旧程度。
    对于租金，jfx只考虑1000以下（包括1000）的，以1000为基准，每便宜1元会增加1点的喜好程度；
    对于房间大小，必须在20以上(包括20)，每大1平米则喜好度增加1；
    对于新旧程度，必须在40以上（包括40），每增加1则喜好度也增加1.

    现在jfx请你帮他选出他喜好程度最好的房子编号，如果有多个，则按照编号从小到大的顺序全部输出。

    # Input
    输入首先包含一个整数T(T <= 100)，表示case的数目。

    对于每组case，首先是1个整个n，代表一共有n个可租的房子( 1<= n <= 10000)。
    接下来有n行，每行4个正整数a，b，c，d( 1<= a <= 1500, 1 <= b <= 100 1 <= c <= 100, 1 <= d <= n)，分别代表该房子的租金，房间大小，新旧程度，编号。

    # Output
    请输出JFX喜好度最高的房间编号，如果有多个，请按编号从小到大顺序全部输出，中间以一个空格分开。

    # Sample Input
    1
    3
    800 40 60 1
    769 40 40 2
    800 41 59 3

    # Sample Output
    2
****/