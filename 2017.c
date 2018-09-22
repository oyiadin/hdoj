#include <stdio.h>
#include <string.h>
#include <ctype.h>

char in[10000];

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%s", in);
        int sum = 0;
        for (int i = 0; i < strlen(in); ++i) {
            if (isdigit(in[i])) ++sum;
        }
        printf("%d\n", sum);
    }
}