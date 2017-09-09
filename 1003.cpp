#include <iostream>
#include <algorithm>

int main() {
    int lines, items, i, j, k;
    std::cin >> lines;

    for (i=1; i<=lines; i++) {
        std::cin >> items;

        int seq[items+1];
        for(j=1; j<=items; j++) std::cin >> seq[j];  // 录入当行数据，seq[0]留空弃用

        int max_h=0, max_s=0, l=items, r=items, fl=items, fr=items;
        bool all_nega=1;
        // 扫描算法
        // max_h为到当前元素为止的子序列sum，max_s为目前找到的最大子序列sum
        // l，r 为临时记录的左右边界，当发现（可能）是更大sum的子序列时，存入fl, fr
        for (k=items; k>=1; k--)
            if (seq[k]>=0) all_nega=0;  // 检测是否特殊情况：全部负数
        // std::cout << "debug: " << all_nega << std::endl;
        for (k=items; k>=1; k--) {  // 由于重复时取第一个，所以从后往前找，最前的答案可覆盖后边的
            if (!all_nega) {
                if (max_h+seq[k]<0) r = k-1;  // 如果子序列sum变得过小，重设右边界
                else l = k;  // 否则，更新左边界

                if ((max_h+seq[k])>=max_s) {  // 如果找到一个(可能)更大的sum值，存入fl, fr
                    fl = l;
                    fr = r;
                    // std::cout << "debug: " << fl << " " << fr << std::endl;
                }

                max_h = std::max(max_h+seq[k], 0);
                max_s = std::max(max_h, max_s);
                // 扫描算法核心语句：
                // 如果已经扫描的子序列sum<0，果断抛弃
                // 时时更新遇到的最大sum值
            } else {  // 如果是全部负数的特殊情况…
                // std::cout << "in" << std::endl;
                if (max_s==0) max_s=seq[1];
                if (seq[k]>=max_s) fl = fr = k;
                max_s = std::max(max_s, seq[k]);
            }
        }
        std::cout << "Case " << i << ":" << std::endl
                  << max_s << " " << fl << " " << fr << std::endl;
        if (i!=lines) std::cout << std::endl;
    }
}