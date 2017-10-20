#include <cstdio>
using namespace std;

int main() {
    int score;
    char grade[11] = {'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A'};
    while (scanf("%d", &score) != -1) {
        if (score < 0 || score > 100) printf("Score is error!\n");
        else printf("%c\n", grade[score / 10]);
    }
}