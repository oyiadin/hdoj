#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;

    while(cin>>n && n) {
        map<string, int> balls;
        decltype(balls.begin()) iter_to_max;
        auto &iter = iter_to_max;
        int max = 0;
        
        for(int i=1; i<=n; i++) {
            string ball;
            cin >> ball;
            balls[ball]++;
            if(balls[ball]>max) {
                iter = balls.find(ball);
                max = balls[ball];
            }
        }
        cout << iter->first << endl;
    }
}