#include"BabboNatale.h"



void BabboNatale(int p, int const *pacchi, int n, unsigned s, bool *curr, bool *best, unsigned *max, unsigned cnt, int sum) {
	if (s == n) {
		if (sum < p && cnt > *max) {
			*max = cnt;
			for (int i = 0; i < n; i++) {
				best[i] = curr[i];
			}
	
		}
		return;
	}

	for (int i = 0; i <= 1; i++) {
		curr[s] = i;
		if (i == 1) {
			cnt++;
			sum += pacchi[s];
		}
		BabboNatale(p, pacchi, n, s + 1,curr, best, max, cnt, sum);
	}

	return;
}

