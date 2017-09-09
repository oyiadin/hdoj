#include <iostream>
#include <memory>
#include <deque>
#include <string>
using namespace std;

inline int to_int(const char s) {
    return (int)s - 48;
}

shared_ptr<string> do_math(string *v1, string *v2) {
    if (v1->size() > v2->size()) swap(v1, v2);
    deque<int> result;

    auto rat1 = v1->rbegin();
    auto rend1 = v1->rend();
    auto rat2 = v2->rbegin();
    auto rend2 = v2->rend();

    int for_next = 0;

    while (true) {
        int tmp_sum = 0;

        if (rat1!=rend1) {
            tmp_sum = to_int(*rat1) + to_int(*rat2) + for_next;
        } else if (rat2!=rend2) {
            tmp_sum = to_int(*rat2) + for_next;
        } else {
            break;
        }

        for_next = tmp_sum / 10;
        result.push_front(tmp_sum%10);

        if (rat1!=rend1) ++rat1;
        ++rat2;
    }
    if (for_next) result.push_front(for_next);

    auto ps_result = make_shared<string>();
    ps_result->reserve(result.size());

    for (auto &i : result) (*ps_result) += to_string(i);

    return ps_result;
}

int main() {
    unsigned n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        string num1, num2;
        cin >> num1 >> num2;

        string result = *do_math(&num1, &num2);

        cout << "Case " << i << ":" << endl
             << num1 << " + " << num2 << " = " << result << endl;
        if (i!=n) cout << endl;
    }
}