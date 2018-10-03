#include <stdio.h>
#include <stdlib.h>

int ability_chi[101], ability_jap[101];


int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i)
			scanf("%d", ability_chi+i);
		for (int i = 0; i < n; ++i)
			scanf("%d", ability_jap+i);

		qsort(ability_chi, n, sizeof(int), cmp);
		qsort(ability_jap, n, sizeof(int), cmp);

		int score_chi = 0, score_jap = 0;

		while (n--) {
			if (ability_chi[n] > ability_jap[n])
				score_chi += 2;
			else if (ability_jap[n] > ability_chi[n])
				score_jap += 2;
			else {
				++score_chi;
				++score_jap;
			}
		}

		printf("%d vs %d\n", score_chi, score_jap);
	}
}