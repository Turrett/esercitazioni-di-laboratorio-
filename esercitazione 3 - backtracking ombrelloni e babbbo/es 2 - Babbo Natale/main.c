#include"BabboNatale.h"

int main(void) {
	int p = 170;
	const int n = 10;
	const int pacchi[10] = { 10,11,1,3,3,40,25,78,30,60 };
	unsigned s = 0;
	bool *curr = malloc(n * sizeof(bool));
	bool *best = malloc(n * sizeof(bool));
	unsigned int *max=malloc(sizeof(int));
	*max = 0;
	unsigned cnt = 0;
	int sum = 0;
	BabboNatale(p, pacchi, n, s, curr, best, max, cnt, sum);
	printf("%d pacchi :", *max);
	for (int i = 0; i < n; i++) {
		printf("%d", best[i]);
	}
	printf("\n");
	return 0;


}