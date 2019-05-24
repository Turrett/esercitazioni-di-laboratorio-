#include "ombrelloni.h"

void Ombrelloni(int k, int n, unsigned s, bool *v, unsigned cnt, unsigned *n_slz){

	if (cnt == k) {
		printf("%4d-", ++(*n_slz));
		memset(v + s, 0, (n - s) * sizeof(bool));
		for (int i = 0; i < n; i++) printf("%d", v[i]);
		printf("\n");
		return;
	}
	if (s == n) return;
	v[s] = 0;
	Ombrelloni(k, n, s + 1, v, cnt, n_slz);

	if (s == 0 || (s> 0 && v[s - 1] == 0)) {
		v[s] = 1;
		Ombrelloni(k, n, s + 1, v, cnt+1, n_slz);
	}
}